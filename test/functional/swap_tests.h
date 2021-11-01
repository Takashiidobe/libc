#include "../../include/assert.h"
#include "../../include/functional/swap.h"

void swap_tests() {
  int x = 10;
  int y = 20;
  swap(&x, &y);
  assert_eq(x, 20);
  assert_eq(y, 10);
  char *def = "def";
  char *abc = "abc";
  swap(&def, &abc);
  assert_eq(abc, "def");
  assert_eq(def, "abc");
}
