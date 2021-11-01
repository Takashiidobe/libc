#ifndef __MAX_H
#define __MAX_H

int maxi(int const x, int const y);

unsigned maxu(unsigned const x, unsigned const y);

long maxl(long const x, long const y);

unsigned long maxul(unsigned long const x, unsigned long const y);

long long maxll(long long const x, long long const y);

unsigned long long maxull(unsigned long long const x,
                          unsigned long long const y);

float maxf(float const x, float const y);

double maxd(double const x, double const y);

long double maxld(long double const x, long double const y);

#define max(X, Y)                                                              \
  (_Generic((X) + (Y), int                                                     \
            : maxi, unsigned                                                   \
            : maxu, long                                                       \
            : maxl, unsigned long                                              \
            : maxul, long long                                                 \
            : maxll, unsigned long long                                        \
            : maxull, float                                                    \
            : maxf, double                                                     \
            : maxd, long double                                                \
            : maxld)((X), (Y)))

#endif
