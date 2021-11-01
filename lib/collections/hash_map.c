#include <stdio.h>
#include <stdlib.h>

#include "../../include/collections/hash_map.h"
#include "../../include/crypto/fnv.h"

static int hashmap_contains_hash(const hashmap_t *map, const uint32_t hash);

static int hashmap_put(hashmap_t *map, const void *key, const void *value);

static int hashmap_retrieve(const uint32_t hash, const size_t capacity);

static void hashmap_resize(hashmap_t *map);

hashmap_t *hashmap_new() {
  hashmap_t *map = malloc(sizeof(hashmap_t));
  map->keys = calloc(DEFAULT_HASH_MAP_CAPACITY, sizeof(void **));
  map->values = calloc(DEFAULT_HASH_MAP_CAPACITY, sizeof(void **));
  map->length = 0;
  map->capacity = DEFAULT_HASH_MAP_CAPACITY;

  return map;
}

int hashmap_add(hashmap_t *map, const void *key, const void *value) {
  return hashmap_put(map, key, (void *)value);
}

void *hashmap_get(const hashmap_t *map, const void *key) {
  int loc = hashmap_retrieve(fnv_32(key), map->capacity);
  if (map->keys[loc] == key) {
    return map->values[loc];
  }
  return NULL;
}

int hashmap_contains(const hashmap_t *map, const void *key) {
  int loc = hashmap_retrieve(fnv_32(key), map->capacity);
  return map->keys[loc] == key ? 1 : 0;
}

void hashmap_delete(hashmap_t *map, const void *value) {
  int loc = hashmap_retrieve(fnv_32(value), map->capacity);

  map->keys[loc] = NULL;
  map->values[loc] = NULL;
}

static int hashmap_put(hashmap_t *map, const void *key, const void *value) {
  uint32_t hash = fnv_32(key);
  int loc = hashmap_retrieve(hash, map->capacity);

  if (hashmap_contains_hash(map, hash)) {
    if (map->keys[loc] == key) {
      return 0;
    }

    hashmap_resize(map);

    return hashmap_put(map, key, value);
  }

  map->keys[loc] = (void *)key;
  map->values[loc] = (void *)value;
  map->length++;

  return 1;
}

static int hashmap_contains_hash(const hashmap_t *map, const uint32_t hash) {
  int loc = hashmap_retrieve(hash, map->capacity);
  return map->keys[loc] ? 1 : 0;
}

static int hashmap_retrieve(const uint32_t hash, const size_t capacity) {
  return (capacity - 1) & (hash ^ (hash >> 12));
}

static void hashmap_resize(hashmap_t *map) {
  map->capacity *= 2;
  void **new_keys = calloc((map->capacity), sizeof(void **));

  for (int i = 0; i < map->length; i++) {
    int prev_loc = hashmap_retrieve(fnv_32(map->keys[i]), map->capacity / 2);
    int new_loc = hashmap_retrieve(fnv_32(map->keys[i]), map->capacity);
    new_keys[new_loc] = map->keys[prev_loc];
  }

  free(map->keys);

  map->keys = new_keys;

  void **new_values =
      (void **)realloc(map->values, map->capacity * sizeof(void **));

  for (int i = 0; i < map->length; i++) {
    int prev_loc = hashmap_retrieve(fnv_32(map->keys[i]), map->capacity / 2);
    int new_loc = hashmap_retrieve(fnv_32(map->keys[i]), map->capacity);
    new_values[new_loc] = map->values[prev_loc];
  }

  free(map->values);

  map->values = new_values;
}
