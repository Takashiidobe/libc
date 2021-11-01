
#ifndef __BSEARCH_TESTS_H
#define __BSEARCH_TESTS_H

#include <assert.h>

#include "../../include/algorithms/bsearch.h"

int int_cmp(const void *a, const void *b) {
  const int arg1 = *(const int *)a;
  const int arg2 = *(const int *)b;
  return (arg1 > arg2) - (arg1 < arg2);
}

void bsearch_tests() {
  int values[] = {5, 20, 29, 32, 63};
  int zero = 0;

  int find_0 = bsearch_index(&zero, values, 5, sizeof(int), int_cmp);

  assert(find_0 == -1);

  int five = 5;
  int find_5 = bsearch_index(&five, values, 5, sizeof(int), int_cmp);

  assert(find_5 == 0);

  int twenty = 20;
  int find_20 = bsearch_index(&twenty, values, 5, sizeof(int), int_cmp);

  assert(find_20 == 1);
}

#endif
