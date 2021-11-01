#include <stdio.h>
#include <stdlib.h>

#include "../../include/collections/hash_set.h"
#include "../../include/crypto/djb2.h"

// static int hashset_put(hashset_t *set, uint32_t hash, void *value);
//
// static int hashset_contains_hash(hashset_t *set, uint32_t hash);
//
// static int hashset_retrieve(const uint32_t hash, const size_t capacity);
//
// static void hashset_resize(hashset_t *set);

// why the distinction between keys and values? Aren't they the same?
// use the hash to find the location of the key.
// on insert:
// if the keys[loc] is not set, set it there.
// otherwise, keep incrementing loc (looping around if needed) to get there.
// on get:
// if the keys[loc] != key,
// keep looping until you find a NULL key.
// on delete:
// find the keys[loc] by looping.
// if we can't find it, do nothing
// otherwise, replace it with a tombstone
// on resize:
// rehash all the keys and place them in the right location.

// static const unsigned int prime_2 = 5009;
static size_t hashset_hash_to_loc(hashset_t *set, size_t hash) {
  return hash % set->capacity;
}

size_t hashset_len(hashset_t *set) { return set->nitems; }

void hashset_free(hashset_t *set) {
  if (set) {
    free(set->items);
  }
  free(set);
}

hashset_t *hashset_new(void) {
  hashset_t *set = malloc(sizeof(struct hashset_st));

  if (set == NULL) {
    return NULL;
  }

  set->nbits = 3;
  set->capacity = (size_t)(1 << set->nbits);
  set->mask = set->capacity - 1;
  set->items = calloc(set->capacity, sizeof(size_t));
  if (set->items == NULL) {
    hashset_free(set);
    return NULL;
  }
  set->nitems = 0;
  set->n_deleted_items = 0;
  return set;
}

static int hashset_add_member_i(hashset_t *set, size_t item) {
  size_t value = item;
  if (value == 0 || value == 1) {
    return -1;
  }

  size_t ii = hashset_hash_to_loc(set, item);

  while (set->items[ii] != 0 && set->items[ii] != 1) {
    if (set->items[ii] == value) {
      return 0;
    }

    ii = (ii + 1) % set->capacity;
  }
  set->nitems++;
  if (set->items[ii] == 1) {
    set->n_deleted_items--;
  }
  set->items[ii] = value;
  return 1;
}

static int hashset_add_member(hashset_t *set, void *item) {
  size_t value = (size_t)item;
  if (value == 0 || value == 1) {
    return -1;
  }

  size_t ii = hashset_hash_to_loc(set, djb2_str_hash(item));

  while (set->items[ii] != 0 && set->items[ii] != 1) {
    if (set->items[ii] == value) {
      return 0;
    }

    ii = (ii + 1) % set->capacity;
  }
  set->nitems++;
  if (set->items[ii] == 1) {
    set->n_deleted_items--;
  }
  set->items[ii] = value;
  return 1;
}

static void maybe_rehash(hashset_t *set) {
  size_t *old_items;
  size_t old_capacity;

  if (set->nitems + set->n_deleted_items >= (double)set->capacity * 0.7) {
    old_items = set->items;
    old_capacity = set->capacity;
    set->nbits++;
    set->capacity = (size_t)(1 << set->nbits);
    set->mask = set->capacity - 1;
    set->items = calloc(set->capacity, sizeof(size_t));
    set->nitems = 0;
    set->n_deleted_items = 0;
    for (size_t ii = 0; ii < old_capacity; ii++) {
      hashset_add_member(set, &old_items[ii]);
    }
    free(old_items);
  }
}

int hashset_add(hashset_t *set, void *item) {
  int rv = hashset_add_member(set, item);
  maybe_rehash(set);
  return rv;
}

int hashset_add_i(hashset_t *set, size_t item) {
  int rv = hashset_add_member_i(set, item);
  maybe_rehash(set);
  return rv;
}

int hashset_delete_i(hashset_t *set, size_t item) {
  size_t value = (size_t)item;

  size_t ii = hashset_hash_to_loc(set, item);

  while (set->items[ii] != 0) {
    if (set->items[ii] == value) {
      set->items[ii] = 1;
      set->nitems--;
      set->n_deleted_items++;
      return 1;
    }

    ii = (ii + 1) % set->capacity;
  }
  return 0;
}

int hashset_delete(hashset_t *set, void *item) {
  size_t value = (size_t)item;

  size_t ii = hashset_hash_to_loc(set, djb2_str_hash(item));

  while (set->items[ii] != 0) {
    if (set->items[ii] == value) {
      set->items[ii] = 1;
      set->nitems--;
      set->n_deleted_items++;
      return 1;
    }

    ii = (ii + 1) % set->capacity;
  }
  return 0;
}

int hashset_contains_i(hashset_t *set, size_t item) {
  size_t value = item;
  printf("Checking if %zu is in the set.\n", value);

  size_t ii = hashset_hash_to_loc(set, value);

  while (set->items[ii] != 0) {
    if (set->items[ii] == value) {
      return 1;
    }
    ii = (ii + 1) % set->capacity;
  }
  return 0;
}

int hashset_contains(hashset_t *set, void *item) {
  size_t value = (size_t)item;
  printf("Checking if %zu is in the set.\n", value);

  size_t ii = hashset_hash_to_loc(set, djb2_str_hash(item));

  while (set->items[ii] != 0) {
    if (set->items[ii] == value) {
      return 1;
    }
    ii = (ii + 1) % set->capacity;
  }
  return 0;
}

// hashset_t *hashset_new() {
//  hashset_t *set = (hashset_t *)malloc(sizeof(hashset_t));
//  set->keys = calloc(DEFAULT_HASH_SET_CAPACITY, sizeof(void **));
//  set->values = calloc(DEFAULT_HASH_SET_CAPACITY, sizeof(void **));
//  set->length = 0;
//  set->capacity = DEFAULT_HASH_SET_CAPACITY;
//
//  return set;
//}
//
// int hashset_add(hashset_t *set, void *value) {
//  puts("adding to hashset");
//  return hashset_put(set, djb2_hash(value), value);
//}
//
// int hashset_contains(hashset_t *set, void *value) {
//  return set->values[hashset_retrieve(djb2_hash(value), set->capacity)] ==
//  value
//             ? 1
//             : 0;
//}
//
// void hashset_delete(hashset_t *set, void *value) {
//  set->values[hashset_retrieve(djb2_hash(value), set->capacity)] = NULL;
//}
//
// static int hashset_put(hashset_t *set, uint32_t hash, void *value) {
//  printf("hash val: %u\n", hash);
//
//  if (hashset_contains_hash(set, hash)) {
//    if (set->values[hashset_retrieve(hash, set->capacity)] == value) {
//      puts("Value was already in set, aborting");
//      return 0;
//    }
//
//    puts("Hash value was found in set but not value, resizing.");
//    hashset_resize(set);
//
//    return hashset_put(set, hash, value);
//  }
//
//  set->values[hashset_retrieve(hash, set->capacity)] = value;
//  set->values[set->length++] = value;
//
//  return 1;
//}
//
// static int hashset_contains_hash(hashset_t *set, uint32_t hash) {
//  return set->values[hashset_retrieve(hash, set->capacity)] ? 1 : 0;
//}
//
// static int hashset_retrieve(const uint32_t hash, const size_t capacity) {
//  int res = (capacity - 1) & (hash ^ (hash >> 12));
//  printf("capacity: %zu, location to retrieve %d\n", capacity, res);
//  return res;
//}
//
// static void hashset_resize(hashset_t *set) {
//  void **keys_resized = calloc((set->capacity <<= 1), sizeof(void **));
//  printf("The new capacity after being resized: %zu\n", set->capacity);
//
//  for (int i = 0; i < set->length; i++) {
//    keys_resized[hashset_retrieve(djb2_hash(set->values[i]), set->capacity)] =
//        set->values[i];
//  }
//
//  free(set->keys);
//
//  set->keys = keys_resized;
//
//  void **new_values =
//      (void **)realloc(set->values, set->capacity * sizeof(void **));
//  set->values = new_values;
//}
