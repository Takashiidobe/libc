#include "../../include/functional/swap.h"

void swapi(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void swapu(unsigned *a, unsigned *b) {
  unsigned temp = *a;
  *a = *b;
  *b = temp;
}

void swapl(long *a, long *b) {
  long temp = *a;
  *a = *b;
  *b = temp;
}

void swapul(unsigned long *a, unsigned long *b) {
  unsigned long temp = *a;
  *a = *b;
  *b = temp;
}

void swapll(long long *a, long long *b) {
  long long temp = *a;
  *a = *b;
  *b = temp;
}

void swapull(unsigned long long *a, unsigned long long *b) {
  unsigned long long temp = *a;
  *a = *b;
  *b = temp;
}

void swapf(float *a, float *b) {
  float temp = *a;
  *a = *b;
  *b = temp;
}

void swapd(double *a, double *b) {
  double temp = *a;
  *a = *b;
  *b = temp;
}

void swapld(long double *a, long double *b) {
  long double temp = *a;
  *a = *b;
  *b = temp;
}

void swaps(char **a, char **b) {
  char *temp = *a;
  *a = *b;
  *b = temp;
}

void swapv(void *a, void *b) {
  void *temp = a;
  a = b;
  b = temp;
}
