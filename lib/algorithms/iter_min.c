// #include "../../include/algorithms/iter_min.h"
// #include <stdlib.h>

// The normal bsearch function.
// void *iter_min(const void *base0, size_t len, size_t size,
//                int (*cmp)(const void *, const void *)) {
//   size_t left = 0;
//   size_t right = len - 1;
//   const char *base = base0;
//
//   while (left <= right) {
//     size_t mid = (left + right) / 2;
//     const char *p = base + (mid * size);
//     int res = (*cmp)(key, p);
//     if (res == 0) {
//       return (void *)p;
//     } else if (res == 1) {
//       left = mid + 1;
//     } else {
//       right = mid - 1;
//     }
//   }
//   return NULL;
// }
