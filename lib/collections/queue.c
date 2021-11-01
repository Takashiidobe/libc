#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
  int *items;
  size_t len;
  size_t capacity;
  size_t head;
  size_t tail;
} Queue;

Queue *new_queue(size_t capacity) {
  Queue *q = malloc(sizeof(Queue));
  q->items = malloc(sizeof(int) * capacity);
  q->capacity = capacity;
  q->head = 0;
  q->tail = 0;
  q->len = 0;
  return q;
}

void print_queue(Queue *q) {
  printf("---- Printing Queue ----\n");
  for (int i = q->head, j = 0; i < q->len; i = (i + 1) % (q->capacity), j++) {
    printf("index: %d item: %d\n", i, q->items[i]);
  }
  printf("---- End of Printing ----\n");
}

void free_queue(Queue *q) {
  free(q->items);
  free(q);
}

void queue_push(Queue *q, int val) {
  assert(q->len < q->capacity);
  q->items[q->tail] = val;
  q->tail = (q->tail + 1) % (q->capacity);
  q->len++;
}

int queue_pop(Queue *q) {
  assert(q->len > 0);
  int res = q->items[q->head];
  q->head = (q->head + 1) % q->capacity;
  q->len--;
  return res;
}

// int main() {
//   Queue *q = new_queue(3);
//   queue_push(q, 10);
//   queue_push(q, 20);
//   queue_push(q, 30);
//   queue_pop(q);
//   queue_pop(q);
//   queue_push(q, 40);
//   queue_push(q, 50);
//   print_queue(q);
//   free_queue(q);
// }
