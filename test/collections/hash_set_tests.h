#include "../../include/collections/hash_set.h"
#include "../../include/crypto/djb2.h"
#include "test_data.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

void hashset_tests() {
  hashset_t *set = hashset_new();

  // const char *v1 = "hi";
  // const char *v2 = "he";

  // assert(1 == hashset_add(set, &v1));
  // assert(0 == hashset_add(set, &v1));
  // assert(1 == hashset_contains(set, &v1));
  // assert(1 == hashset_add(set, &v2));
  // assert(0 == hashset_add(set, &v2));
  // assert(1 == hashset_contains(set, &v2));
  // hashset_delete(set, &v1);
  // assert(0 == hashset_contains(set, &v1));
  // hashset_delete(set, &v2);

  // const char *first = data[0];
  // const char *second = strdup(data[0]);

  // printf("first hash: %u, first ptr %p, second hash: %u, second ptr %p\n",
  //        djb2_str_hash(first), (void *)first, djb2_str_hash(second),
  //        (void *)second);

  // printf("did inserting first succeed? %d\n", hashset_add(set, &first));

  // printf("%s in the set?: %d\n", second, hashset_contains(set, &second));

  // printf("Set capacity: %zu\n", set->capacity);

  // puts("Set Items");
  // for (size_t i = 0; i < set->capacity; i++) {
  //   printf("Item %zu: %zu\n", i, set->items[i]);
  // }

  for (size_t i = 0; i < 10000; i++) {
    printf("Trying to insert: %zu\n", i);
    hashset_add_i(set, i);
  }
  for (size_t i = 0; i < 20000; i++) {
    printf("is %zu in the set?: %d\n", i, hashset_contains_i(set, i));
  }

  printf("set capacity: %zu\n", set->capacity);
  printf("set length: %zu\n", hashset_len(set) - set->n_deleted_items);

  // size_t data_len = sizeof(data) / sizeof(data[0]);

  // for (int i = 0; i < data_len; i++) {
  //   const char *str = data[i];
  //   printf("Trying to insert: %s\n", str);
  //   hashset_add(set, &str);
  // }

  // for (int i = 0; i < data_len; i++) {
  //   const char *str = data[i];
  //   printf("is %s in the set?: %d\n", str, hashset_contains(set, &str));
  // }

  // printf("set capacity: %zu\n", set->capacity);
  // printf("set length: %zu\n", hashset_len(set));
}
