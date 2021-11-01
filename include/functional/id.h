#ifndef __ID_H
#define __ID_H

const int idi(int const x);

const unsigned idu(unsigned const x);

const long idl(long const x);

const unsigned long idul(unsigned long const x);

const long long idll(long long const x);

const unsigned long long idull(unsigned long long const x);

const float idf(float const x);

const double idd(double const x);

const long double idld(long double const x);

const char *ids(const char *x);

#define id(X)                                                                  \
  (_Generic((X), int                                                     \
            : idi, unsigned                                                   \
            : idu, long                                                       \
            : idl, unsigned long                                              \
            : idul, long long                                                 \
            : idll, unsigned long long                                        \
            : idull, float                                                    \
            : idf, double                                                     \
            : idd, long double                                                \
            : idld, char[sizeof(X)]                                     \
            : ids, char *                                                     \
            : ids)((X)))
#endif
