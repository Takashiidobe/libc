#include "../../include/assert.h"
#include "../../include/functional/eq.h"

void eq_tests() {
  assert_eq(eq(10, 10), 1);
  assert_eq(eq(0, 10), 0);
  assert_eq(eq(10, 0), 0);
  assert_eq(eq(10ul, 20ul), 0);
  assert_eq(eq(20ul, 20ul), 1);
  assert_eq(eq(30ul, 20ul), 0);
  assert_eq(eq("", ""), 1);
  assert_eq(eq("hi", ""), 1);
  assert_eq(eq("", "hi"), 0);
  assert_eq(eq("abc", "abc"), 1);
  assert_eq(eq("abc", "def"), 0);
  assert_eq(eq("def", "abc"), 0);
}
