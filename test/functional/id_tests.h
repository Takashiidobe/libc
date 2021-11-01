#include "../../include/assert.h"
#include "../../include/functional/id.h"

void id_tests() {
  assert_eq(id(10), 10);
  assert_eq(id(-10), -10);
  assert_eq(id("hi"), "hi");
  assert_eq(id(100ul), 100ul);
  assert_eq(id(90ull), 90ull);
}
