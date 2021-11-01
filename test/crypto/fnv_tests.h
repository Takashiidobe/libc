#include <assert.h>

#include "../../include/crypto/fnv.h"

void fnv_test() {
  uint64_t first = fnv_64("Hello");
  uint64_t second = fnv_64("hello");
  assert(first == 7201466553693376363UL);
  assert(second == 11831194018420276491UL);
}
