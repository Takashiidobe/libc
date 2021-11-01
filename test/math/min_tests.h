#include "../../include/assert.h"
#include "../../include/math/min.h"

void min_tests() {
  assert_eq(min(10, 20), 10);
  assert_eq(min(-1, -5), -5);
  assert_eq(min(0, 0), 0);
  assert_eq(min(20u, 10u), 10u);
  assert_eq(min(20ul, 10ul), 10ul);
  assert_eq(min(20ul, 10ul), 10ul);
  assert_eq(min(20ull, 10ull), 10ull);
  assert_eq(min(-20ll, -10ll), -20ll);
  assert_eq(min(20.0f, 10.0f), 10.0f);
  assert_eq(min(-10.0f, -20.0f), -20.0f);
  assert_eq(min(-10.0, -20.0), -20.0);
  assert_eq(min(-10.0f, -20.0f), -20.0f);
}
