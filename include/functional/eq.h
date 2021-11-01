#ifndef __EQ_H
#define __EQ_H

#include <string.h>

int eqi(int const x, int const y);

int equ(unsigned const x, unsigned const y);

int eql(long const x, long const y);

int equl(unsigned long const x, unsigned long const y);

int eqll(long long const x, long long const y);

int equll(unsigned long long const x, unsigned long long const y);

int eqf(float const x, float const y);

int eqd(double const x, double const y);

int eqld(long double const x, long double const y);

int eqs(const char *x, const char *y);

#define eq(X, Y)                                                               \
  (_Generic((X, Y), int                                                        \
            : eqi, unsigned                                                    \
            : equ, long                                                        \
            : eql, unsigned long                                               \
            : equl, long long                                                  \
            : eqll, unsigned long long                                         \
            : equll, float                                                     \
            : eqf, double                                                      \
            : eqd, long double                                                 \
            : eqld, char[sizeof(X)]                                            \
            : eqs, char *                                                      \
            : eqs)((X), (Y)))
#endif
