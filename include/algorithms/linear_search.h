#ifndef __LINEAR_SEARCH_H
#define __LINEAR_SEARCH_H

#include <stdio.h>
#include <string.h>

int linear_search(const void *key, const void *base0, size_t len, size_t size,
                  int (*cmp)(const void *, const void *));

#endif
