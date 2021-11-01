#ifndef __HASH_MAP_H
#define __HASH_MAP_H

#include <stddef.h>
#include <stdint.h>

static const size_t DEFAULT_HASH_MAP_CAPACITY = 128;

typedef struct {
  size_t capacity;
  size_t length;
  void **keys;
  void **values;
} hashmap_t;

hashmap_t *hashmap_new();

int hashmap_add(hashmap_t *map, const void *key, const void *value);

void *hashmap_get(const hashmap_t *map, const void *key);

void hashmap_delete(hashmap_t *map, const void *key);

int hashmap_contains(const hashmap_t *map, const void *key);

#endif
