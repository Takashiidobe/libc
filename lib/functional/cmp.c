#include "../../include/functional/cmp.h"

int cmpi(int const x, int const y) { return (x == y) ? 0 : (x > y) ? 1 : -1; }

int cmpu(unsigned const x, unsigned const y) {
  return (x == y) ? 0 : (x > y) ? 1 : -1;
}

int cmpl(long const x, long const y) { return (x == y) ? 0 : (x > y) ? 1 : -1; }

int cmpul(unsigned long const x, unsigned long const y) {
  return (x == y) ? 0 : (x > y) ? 1 : -1;
}

int cmpll(long long const x, long long const y) {
  return (x == y) ? 0 : (x > y) ? 1 : -1;
}

int cmpull(unsigned long long const x, unsigned long long const y) {
  return (x == y) ? 0 : (x > y) ? 1 : -1;
}

int cmpf(float const x, float const y) {
  return (x == y) ? 0 : (x > y) ? 1 : -1;
}

int cmpd(double const x, double const y) {
  return (x == y) ? 0 : (x > y) ? 1 : -1;
}

int cmpld(long double const x, long double const y) {
  return (x == y) ? 0 : (x > y) ? 1 : -1;
}

int cmps(const char *x, const char *y) {
  if (strcmp(x, y) == 0) {
    return 0;
  }
  if (strcmp(x, y) > 0) {
    return 1;
  }
  return -1;
}
