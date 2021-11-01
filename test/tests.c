#include "algorithms/bsearch_tests.h"
#include "collections/hash_map_tests.h"
#include "collections/hash_set_tests.h"
#include "collections/heap_tests.h"
#include "collections/tuples_tests.h"
#include "crypto/fnv_tests.h"
#include "functional/functional_tests.h"
#include "math/math_tests.h"
#include "utils/logger_tests.h"
#include <time.h>

void time_test(void (*fn)(), const char *name) {
  clock_t begin = clock();
  clock_t end = clock();
  fn();
  double time_spent = (double)(end - begin) * 1000.0f / CLOCKS_PER_SEC;

  printf("Completed %s tests in %0.3f milliseconds.\n", name, time_spent);
}

int main() {
  // time_test(fnv_test, "FNV tests");
  // time_test(tuple_test, "Tuple tests");
  // time_test(bsearch_tests, "Bsearch Tests");
  // time_test(heap_tests, "Heap Tests");
  // time_test(min_tests, "Min Tests");
  // time_test(max_tests, "Max Tests");
  // time_test(id_tests, "Id Tests");
  // time_test(cmp_tests, "Cmp Tests");
  // time_test(eq_tests, "Eq Tests");
  // time_test(swap_tests, "Swap Tests");
  // time_test(logger_tests, "Logger Tests");
  time_test(hashset_tests, "Hash Set Tests");
  // time_test(hashmap_tests, "Hash Map Tests");
}
