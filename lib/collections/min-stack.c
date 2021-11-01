#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// # MinStack
// A min_stack that allows for an O(1) query for the minimum value in the
// min_stack.
typedef struct MinStackNode {
  int val;
  int min;
} MinStackNode;

typedef struct MinStack {
  MinStackNode **nodes;
  size_t len;
  size_t capacity;
} MinStack;

//
// ## Interface
// ```c
// MinStack *min_stack_new(size_t capacity)
// ```
// Create a heap allocated min_stack.
// Must be freed at the end of its use.
MinStack *min_stack_new(size_t capacity) {
  MinStack *s = malloc(sizeof(MinStack));
  s->nodes = malloc(sizeof(MinStackNode) * capacity);
  s->len = 0;
  s->capacity = capacity;
  return s;
}

// ```c
// int min_stack_min(MinStack *s)
// ```
// Returns the minimum value of the min_stack.
// If the min_stack is empty, returns -1.
int min_stack_min(MinStack *s) {
  if (s->len == 0)
    return -1;
  return s->nodes[s->len - 1]->min;
}

// ```c
// void min_stack_push(MinStack *s, int val)
// ```
// Pushes a value onto the min_stack.
// If the min_stack exceeds its capacity, fails with an assert.
void min_stack_push(MinStack *s, int val) {
  assert(s->len < s->capacity);
  MinStackNode *n = malloc(sizeof(MinStackNode));
  n->val = val;
  if (s->len == 0) {
    n->min = val;
  } else {
    n->min = val > s->nodes[s->len - 1]->min ? s->nodes[s->len - 1]->min : val;
  }
  s->nodes[s->len] = n;
  s->len++;
}

// ```c
// int min_stack_peek(MinStack *s)
// ```
// Returns the top value of min_stack.
// If the min_stack is empty, returns -1.
int min_stack_peek(MinStack *s) {
  if (s->len == 0)
    return -1;
  return s->nodes[s->len - 1]->val;
}

// ```c
// int min_stack_pop(MinStack *s)
// ```
// Returns the top value of the min_stack.
// If the min_stack is empty, exits immediately with an assert.
int min_stack_pop(MinStack *s) {
  assert(s->len > 0);
  s->len--;
  int popped = s->nodes[s->len]->val;
  free(s->nodes[s->len]);
  return popped;
}

// ```c
// void min_stack_free(MinStack *s)
// ```
// Frees every node in the min_stack and then frees the min_stack itself.
void min_stack_free(MinStack *s) {
  for (size_t i = 0; i < s->len; i++) {
    free(s->nodes[i]);
  }
  free(s);
}

//
// ## Example
// ```c
// #include "min_stack.h"
// MinStack *s = min_stack_new(10); // Initialize a new min_stack with a
// capacity of 10. min_stack_push(s, 20); // Push 20 onto the min_stack.
// min_stack_push(s, 10); // Push 10 onto the min_stack. The minimum is now 10.
// min_stack_peek(s); // The top of the min_stack, 10.
// min_stack_min(s); // The minimum of the min_stack, 10.
// min_stack_pop(s); // Pop 10 from the min_stack.
// min_stack_min(s); // The minimum of the min_stack, 20.
// min_stack_free(s); // free the min_stack.
// ```
