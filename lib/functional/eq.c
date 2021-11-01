#include "../../include/functional/eq.h"

int eqi(int const x, int const y) { return x == y; }

int equ(unsigned const x, unsigned const y) { return x == y; }

int eql(long const x, long const y) { return x == y; }

int equl(unsigned long const x, unsigned long const y) { return x == y; }

int eqll(long long const x, long long const y) { return x == y; }

int equll(unsigned long long const x, unsigned long long const y) {
  return x == y;
}

int eqf(float const x, float const y) { return x == y; }

int eqd(double const x, double const y) { return x == y; }

int eqld(long double const x, long double const y) { return x == y; }

int eqs(const char *x, const char *y) { return !strcmp(x, y); }
