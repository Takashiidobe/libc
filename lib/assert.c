#include "../include/assert.h"

void assert_fail(const char *expr, const char *file, int line,
                 const char *func) {
  fprintf(stderr, "assertion \"%s\" failed: file \"%s\", line %d\n",
          "expression", __FILE__, __LINE__);
  fflush(NULL);
  abort();
}

void assert_eqi(const int x, const int y) {
  x != y &&
      (assert_fail("x does not equal y", __FILE__, __LINE__, __func__), 0);
}

void assert_equ(const unsigned x, const unsigned y) {
  x != y &&
      (assert_fail("x does not equal y", __FILE__, __LINE__, __func__), 0);
}

void assert_eql(const long x, const long y) {
  x != y &&
      (assert_fail("x does not equal y", __FILE__, __LINE__, __func__), 0);
}
void assert_equl(const unsigned long x, const unsigned long y) {
  x != y &&
      (assert_fail("x does not equal y", __FILE__, __LINE__, __func__), 0);
}

void assert_eqll(const long long x, const long long y) {
  x != y &&
      (assert_fail("x does not equal y", __FILE__, __LINE__, __func__), 0);
}

void assert_equll(const unsigned long long x, const unsigned long long y) {
  x != y &&
      (assert_fail("x does not equal y", __FILE__, __LINE__, __func__), 0);
}

void assert_eqf(const float x, const float y) {
  x != y &&
      (assert_fail("x does not equal y", __FILE__, __LINE__, __func__), 0);
}
void assert_eqd(const double x, const double y) {
  x != y &&
      (assert_fail("x does not equal y", __FILE__, __LINE__, __func__), 0);
}
void assert_eqld(const long double x, const long double y) {
  x != y &&
      (assert_fail("x does not equal y", __FILE__, __LINE__, __func__), 0);
}
void assert_eqs(const char *x, const char *y) {
  strcmp(x, y) != 0 &&
      (assert_fail("x does not equal y", __FILE__, __LINE__, __func__), 0);
}

void assert_eqia(const int x[], const size_t x_len, const int y[],
                 const size_t y_len) {
  if (x_len != y_len)
    (assert_fail("the length of x is not equal to the length of y", __FILE__,
                 __LINE__, __func__),
     0);
  for (size_t i = 0; i < x_len && i < y_len; i++) {
    if (x[i] != y[i])
      (assert_fail("x does not equal y", __FILE__, __LINE__, __func__), 0);
  }
}
