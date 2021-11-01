#ifndef __CMP_H
#define __CMP_H

#include <string.h>

int cmpi(int const x, int const y);

int cmpu(unsigned const x, unsigned const y);

int cmpl(long const x, long const y);

int cmpul(unsigned long const x, unsigned long const y);

int cmpll(long long const x, long long const y);

int cmpull(unsigned long long const x, unsigned long long const y);

int cmpf(float const x, float const y);

int cmpd(double const x, double const y);

int cmpld(long double const x, long double const y);

int cmps(const char *x, const char *y);

#define cmp(X, Y)                                                              \
  (_Generic((X, Y), int                                                     \
            : cmpi, unsigned                                                   \
            : cmpu, long                                                       \
            : cmpl, unsigned long                                              \
            : cmpul, long long                                                 \
            : cmpll, unsigned long long                                        \
            : cmpull, float                                                    \
            : cmpf, double                                                     \
            : cmpd, long double                                                \
            : cmpld, char[sizeof(X)]                                     \
            : cmps, char *                                                     \
            : cmps)((X), (Y)))
#endif
