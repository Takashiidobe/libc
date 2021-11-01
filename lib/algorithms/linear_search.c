#include "../../include/algorithms/linear_search.h"

int linear_search(const void *key, const void *base0, size_t len, size_t size,
                  int (*cmp)(const void *, const void *)) {
  const char *base = base0;

  for (size_t i = 0; i < len; i++) {
    const char *p = base + (i * size);
    int res = (*cmp)(key, p);
    if (res == 1) {
      return 1;
    }
  }
  return 0;
}

// int main(void) {
//   const char *items[3] = {"hi", "hello", "world"};
//   const char *key = "hi";
//   int res = linear_search(&key, &items, 3, sizeof(const char *), str_eq);
// }
