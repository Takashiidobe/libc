#ifndef ASSERT_H
#define ASSERT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void assert_fail(const char *expr, const char *file, int line,
                 const char *func);

void assert_eqi(const int x, const int y);

void assert_equ(const unsigned x, const unsigned y);

void assert_eql(const long x, const long y);

void assert_equl(const unsigned long x, const unsigned long y);

void assert_eqll(const long long x, const long long y);

void assert_equll(const unsigned long long x, const unsigned long long y);

void assert_eqf(const float x, const float y);

void assert_eqd(const double x, const double y);

void assert_eqld(const long double x, const long double y);

void assert_eqs(const char *x, const char *y);

void assert_eqia(const int x[], const size_t x_len, const int y[],
                 const size_t y_len);

#ifdef NDEBUG
#define assert_eq(x, y) (void)0
#else
#define assert_eq(x, y)                                                        \
  (_Generic((x, y), int                                                     \
            : assert_eqi, unsigned                                                   \
            : assert_equ, char: assert_equ, long                                                   \
            : assert_eql, unsigned long                                              \
            : assert_equl, long long                                                 \
            : assert_eqll, unsigned long long                                        \
            : assert_equll, float                                                    \
            : assert_eqf, double                                                     \
            : assert_eqd, long double                                                \
            : assert_eqld, char *                                               \
            : assert_eqs))
#endif

#ifdef NDEBUG
#define assert_eqa(x, x_len, y, y_len) (void)0
#else
#define assert_eqa(x, x_len, y, y_len)                                         \
  (_Generic((x), int[sizeof(int)] : assert_eqia, int * : assert_eqia))((x), (x_len), (y), (y_len))
#endif

#endif
