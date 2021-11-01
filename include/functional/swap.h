#ifndef __SWAP_H
#define __SWAP_H

void swapi(int *x, int *y);
void swapu(unsigned *x, unsigned *y);
void swapl(long *x, long *y);
void swapul(unsigned long *x, unsigned long *y);
void swapll(long long *x, long long *y);
void swapull(unsigned long long *x, unsigned long long *y);
void swapf(float *x, float *y);
void swapd(double *x, double *y);
void swapld(long double *x, long double *y);
void swaps(char **x, char **y);
void swapv(void *x, void *y);

#define swap(X, Y)                                                             \
  (_Generic((X, Y), int *                                                    \
            : swapi, unsigned *                                                  \
            : swapu, long *                                                  \
            : swapl, unsigned long *                                             \
            : swapul, long long *                                                \
            : swapll, unsigned long long*                                        \
            : swapull, float *                                                   \
            : swapf, double *                                                    \
            : swapd, long double *                                               \
            : swapld, char **                                               \
            : swaps, void* : swapv)(X, Y))
#endif
