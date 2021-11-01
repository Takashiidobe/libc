#include "../../include/algorithms/bsearch.h"
#include <stdlib.h>

// check if the item is in the array.
// Returns -1 if not, otherwise returns array index.
int bsearch_index(const void *key, const void *base0, size_t len, size_t size,
                  int (*cmp)(const void *, const void *)) {

  size_t left = 0;
  size_t right = len - 1;
  const char *base = base0;

  while (left <= right) {
    size_t mid = (left + right) / 2;
    const char *p = base + (mid * size);
    int res = (*cmp)(key, p);
    if (res == 0) {
      return mid;
    } else if (res == 1) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return -1;
}

// Check if the item is in the array.
// Returns 0 if not, or 1 if in the array.
int bsearch_contains(const void *key, const void *base0, size_t len,
                     size_t size, int (*cmp)(const void *, const void *)) {

  size_t left = 0;
  size_t right = len - 1;
  const char *base = base0;

  while (left <= right) {
    size_t mid = (left + right) / 2;
    const char *p = base + (mid * size);
    int res = (*cmp)(key, p);
    if (res == 0) {
      return 1;
    } else if (res == 1) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return 0;
}

// The normal bsearch function.
void *bsearch(const void *key, const void *base0, size_t len, size_t size,
              int (*cmp)(const void *, const void *)) {
  size_t left = 0;
  size_t right = len - 1;
  const char *base = base0;

  while (left <= right) {
    size_t mid = (left + right) / 2;
    const char *p = base + (mid * size);
    int res = (*cmp)(key, p);
    if (res == 0) {
      return (void *)p;
    } else if (res == 1) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return NULL;
}
