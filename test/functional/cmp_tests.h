#include "../../include/assert.h"
#include "../../include/functional/cmp.h"

void cmp_tests() {
  assert_eq(cmp(10, 10), 0);
  assert_eq(cmp(0, 10), -1);
  assert_eq(cmp(10, 0), 1);
  assert_eq(cmp(10ul, 20ul), -1);
  assert_eq(cmp(20ul, 20ul), 0);
  assert_eq(cmp(30ul, 20ul), 1);
  assert_eq(cmp("", ""), 0);
  assert_eq(cmp("hi", ""), -1);
  assert_eq(cmp("", "hi"), 1);
  assert_eq(cmp("abc", "abc"), 0);
  assert_eq(cmp("abc", "def"), -1);
  assert_eq(cmp("def", "abc"), 1);
}
