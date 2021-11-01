#include "../../include/math/min.h"

int mini(int const x, int const y) { return y < x ? y : x; }

unsigned minu(unsigned const x, unsigned const y) { return y < x ? y : x; }

long minl(long const x, long const y) { return y < x ? y : x; }

unsigned long minul(unsigned long const x, unsigned long const y) {
  return y < x ? y : x;
}

long long minll(long long const x, long long const y) { return y < x ? y : x; }

unsigned long long minull(unsigned long long const x,
                          unsigned long long const y) {
  return y < x ? y : x;
}

float minf(float const x, float const y) { return y < x ? y : x; }

double mind(double const x, double const y) { return y < x ? y : x; }

long double minld(long double const x, long double const y) {
  return y < x ? y : x;
}
