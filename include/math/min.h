#ifndef __MIN_H
#define __MIN_H

#define min(X, Y)                                                              \
  (_Generic((X) + (Y), int                                                     \
            : mini, unsigned                                                   \
            : minu, long                                                       \
            : minl, unsigned long                                              \
            : minul, long long                                                 \
            : minll, unsigned long long                                        \
            : minull, float                                                    \
            : minf, double                                                     \
            : mind, long double                                                \
            : minld)((X), (Y)))

int mini(int const x, int const y);

unsigned minu(unsigned const x, unsigned const y);

long minl(long const x, long const y);

unsigned long minul(unsigned long const x, unsigned long const y);

long long minll(long long const x, long long const y);

unsigned long long minull(unsigned long long const x,
                          unsigned long long const y);

float minf(float const x, float const y);

double mind(double const x, double const y);

long double minld(long double const x, long double const y);

#endif
