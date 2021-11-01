#ifndef __HASH_SET_H
#define __HASH_SET_H

#include <stddef.h>
#include <stdint.h>

static const size_t DEFAULT_HASH_SET_CAPACITY = 128;

struct hashset_st {
  size_t nbits;
  size_t mask;

  size_t capacity;
  size_t *items;
  size_t nitems;
  size_t n_deleted_items;
};

typedef struct hashset_st hashset_t;

// typedef struct {
//   size_t capacity;
//   size_t length;
//   void **values;
//   void **keys;
// } hashset_t;

hashset_t *hashset_new(void);

size_t hashset_len(hashset_t *set);

int hashset_contains(hashset_t *set, void *value);

int hashset_add(hashset_t *set, void *value);

int hashset_delete(hashset_t *set, void *value);

int hashset_contains_i(hashset_t *set, size_t value);

int hashset_add_i(hashset_t *set, size_t value);

int hashset_delete_i(hashset_t *set, size_t value);

#endif
