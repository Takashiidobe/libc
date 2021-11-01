#include <assert.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../include/math/math.h"

typedef struct Stack {
  const void **items;
  size_t len;
  size_t capacity;
} Stack;

// Allow the user to set their own alloc/free
static void *(*__stack_malloc)(size_t) = malloc;
static void *(*__stack_realloc)(void *, size_t) = realloc;
static void (*__stack_free)(void *) = free;

void stack_set_alloc(void *(malloc)(size_t), void *(realloc)(void *, size_t),
                     void (*free)(void *)) {
  __stack_malloc = malloc;
  __stack_realloc = realloc;
  __stack_free = free;
}

Stack *stack_new(const size_t len, ...) {
  Stack *s = __stack_malloc(sizeof(Stack));
  int capacity = 8;
  capacity = max(pow(2, ceil(log(len) / log(2))), capacity);

  s->items = __stack_malloc(sizeof(int) * capacity);
  s->len = len;
  s->capacity = capacity;

  if (len > 0) {
    va_list argp;
    va_start(argp, len);

    for (size_t i = 0; i < len; i++) {
      s->items[i] = va_arg(argp, void *);
    }

    va_end(argp);
  }

  return s;
}

void stack_push(Stack *s, const void *item) {
  if (s->len == s->capacity) {
    s->items = realloc(s->items, sizeof(const void *) * s->capacity * 2);
    if (s->items == NULL)
      assert("Stack could not increase in size.");
    s->capacity *= 2;
  }
  s->items[s->len++] = item;
}

void stack_pop(Stack *s) {
  s->items[s->len - 1] = NULL;
  free((void *)s->items[s->len - 1]);
  s->len--;
}

const void *stack_peek(Stack *s) { return s->items[s->len - 1]; }

void stack_for_each(Stack *s, const void *(*fn)(const void *)) {
  for (size_t i = 0; i < s->len; i++) {
    s->items[i] = (*fn)(s->items[i]);
  }
}

void stack_print(Stack *s) {
  printf("Stack capacity: %lu\n", s->capacity);
  printf("Stack Length: %lu\n", s->len);
  printf("Items: ");
  for (int i = 0; i < s->len; i++) {
    printf("%d ", *(int *)s->items[i]);
  }
}

int stack_empty(Stack *s) { return s->len == 0; }

const void *add10(const void *i) {
  const char *s = i;
  return s + 10;
}
