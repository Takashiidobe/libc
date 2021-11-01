#include "../../include/assert.h"
#include "../../include/collections/hash_map.h"
#include "test_data.h"

void hashmap_tests() {
  hashmap_t *map = hashmap_new();

  const char *k1 = "key1";
  const char *v1 = "value1";
  const char *k2 = "key2";
  const char *v2 = "value2";

  hashmap_add(map, &k1, &v1);
  char *get_res1 = *(char **)hashmap_get(map, &k1);
  printf("get_res1: %s\n", get_res1);

  assert_eq(k1, get_res1);

  assert_eq(1, map->length);
  assert_eq(1, hashmap_contains(map, &v1));
  assert_eq(1, hashmap_add(map, &k2, &v2));
  assert_eq(0, hashmap_add(map, &k2, &v2));

  char *get_res2 = *(char **)hashmap_get(map, &k2);
  printf("res2: %s\n", get_res2);

  assert_eq(k2, get_res2);
  assert_eq(1, hashmap_contains(map, &k2));
  hashmap_delete(map, &k1);
  assert_eq(0, hashmap_contains(map, &k1));
  assert_eq(1, map->length);

  size_t data_len = sizeof(data) / sizeof(data[0]);

  for (int i = 1; i < data_len; i++) {
    const char *str = data[i];
    const char *prev = data[data_len - 1];
    assert_eq(1, hashmap_add(map, &str, &prev));
    assert_eq(0, hashmap_add(map, &str, &prev));
    assert_eq(1, hashmap_contains(map, &str));
  }

  for (int i = 0; i < data_len; i++) {
    printf("(key: %s value: %s)\n", *(char **)map->keys[i],
           *(char **)map->values[i]);
  }
}
