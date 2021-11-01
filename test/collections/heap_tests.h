#include "../../include/assert.h"
#include "../../include/collections/heap.h"

void heap_tests() {
  int arr[] = {12, 11, 13, 5, 6, 7, 20, -1, -3};
  int arr_len = 9;

  int sorted[] = {-3, -1, 5, 6, 7, 11, 12, 13, 20};
  int sorted_len = 9;

  heap_sort(arr, arr_len);

  assert_eqa(arr, arr_len, sorted, sorted_len);
}
