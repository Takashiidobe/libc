#include "../../include/assert.h"
#include "../../include/math/max.h"

void max_tests() {
  assert_eq(max(10, 20), 20);
  assert_eq(max(-1, -5), -1);
  assert_eq(max(0, 0), 0);
  assert_eq(max(20u, 10u), 20u);
  assert_eq(max(20ul, 10ul), 20ul);
  assert_eq(max(20ul, 10ul), 20ul);
  assert_eq(max(20ull, 10ull), 20ull);
  assert_eq(max(-20ll, -10ll), -10ll);
  assert_eq(max(20.0f, 10.0f), 20.0f);
  assert_eq(max(-10.0f, -20.0f), -10.0f);
  assert_eq(max(-10.0, -20.0), -10.0);
  assert_eq(max(-10.0f, -20.0f), -10.0f);
}
