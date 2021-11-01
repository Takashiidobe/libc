#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Deque {
  int *items;
  size_t len;
  size_t capacity;
  size_t head;
  size_t tail;
} Deque;

Deque *new_deque(size_t capacity) {
  Deque *q = malloc(sizeof(Deque));
  q->items = malloc(sizeof(int) * capacity);
  q->capacity = capacity;
  q->head = 0;
  q->tail = 0;
  q->len = 0;
  return q;
}

void print_deque(Deque *q) {
  printf("---- Printing Deque ----\n");
  for (int i = q->head, j = 0; i < q->len; i = (i + 1) % (q->capacity), j++) {
    printf("index: %d item: %d\n", i, q->items[i]);
  }
  printf("---- End of Printing ----\n");
}

void free_deque(Deque *q) {
  free(q->items);
  free(q);
}

void deque_push(Deque *q, int val) {
  assert(q->len < q->capacity);
  q->items[q->tail] = val;
  q->tail = (q->tail + 1) % (q->capacity);
  q->len++;
}

int deque_pop(Deque *q) {
  assert(q->len > 0);
  int res = q->items[q->head];
  q->head = (q->head + 1) % q->capacity;
  q->len--;
  return res;
}

// int main() {
//     Deque *q = new_deque(3);
//     deque_push(q, 10);
//     deque_push(q, 20);
//     deque_push(q, 30);
//     deque_pop(q);
//     deque_pop(q);
//     deque_push(q, 40);
//     deque_push(q, 50);
//     print_deque(q);
//     free_deque(q);
// }
