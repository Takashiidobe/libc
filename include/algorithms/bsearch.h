#ifndef __BSEARCH_H
#define __BSEARCH_H

#include <stdlib.h>

int bsearch_index(const void *key, const void *base0, size_t len, size_t size,
                  int (*cmp)(const void *, const void *));

int bsearch_contains(const void *key, const void *base0, size_t len,
                     size_t size, int (*cmp)(const void *, const void *));

void *bsearch(const void *key, const void *base0, size_t len, size_t size,
              int (*cmp)(const void *, const void *));

#endif
