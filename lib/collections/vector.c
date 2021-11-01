#include "../../include/collections/vector.h"

// Allow the user to set their own alloc/free
static void *(*__vector_malloc)(size_t) = malloc;
static void *(*__vector_realloc)(void *, size_t) = realloc;
static void (*__vector_free)(void *) = free;

void vector_set_alloc(void *(malloc)(size_t), void *(realloc)(void *, size_t),
                      void (*free)(void *)) {
  __vector_malloc = malloc;
  __vector_realloc = realloc;
  __vector_free = free;
}

Vector *vector_new(const size_t len, ...) {
  Vector *v = __vector_malloc(sizeof(Vector));
  int capacity = 8;
  capacity = max(pow(2, ceil(log(len) / log(2))), capacity);

  v->items = __vector_malloc(sizeof(int) * capacity);
  v->len = len;
  v->capacity = capacity;

  if (len > 0) {
    va_list argp;
    va_start(argp, len);

    for (size_t i = 0; i < len; i++) {
      v->items[i] = va_arg(argp, int);
    }

    va_end(argp);
  }

  return v;
}

Vector *vector_copy(const Vector *v) {
  Vector *copy = __vector_malloc(sizeof(Vector));
  copy->items = malloc(sizeof(int) * v->len);
  copy->capacity = v->capacity;
  copy->len = v->len;

  for (size_t i = 0; i < v->len; i++)
    copy->items[i] = v->items[i];

  return copy;
}

void vector_free(Vector *v) {
  __vector_free(v->items);
  __vector_free(v);
}

int vector_get(Vector *v, size_t index) {
  assert(index >= 0 && index < v->len);
  return v->items[index];
}

void vector_set(Vector *v, size_t index, int val) {
  assert(index >= 0 && index < v->len);
  v->items[index] = val;
}

int vector_empty(Vector *v) { return v->len == 0; }

void vector_push(Vector *v, int val) {
  if (v->len == v->capacity) {
    v->capacity *= 2;
    v->items = __vector_realloc(v->items, sizeof(int) * v->capacity);
  }
  v->items[v->len] = val;
  v->len++;
}

int *vector_begin(Vector *v) { return &v->items[0]; }

int *vector_end(Vector *v) { return &v->items[v->len]; }

int *vector_next(Vector *v, int *it) {
  if (it != vector_end(v))
    return ++it;
  return NULL;
}

void vector_for_each(Vector *v, int (*fn)(int)) {
  for (int i = 0; i < v->len; i++) {
    v->items[i] = (*fn)(v->items[i]);
  }
}

int vector_peek(Vector *v) { return v->items[v->len - 1]; }

int vector_pop(Vector *v) {
  assert(v->len > 0);
  int top = vector_peek(v);
  v->len--;
  return top;
}

// int main(void) {
//     Vector* v = vector_new(8, 0, 1, 2, 3, 4, 5, 6, 7);
//
//     printf("begin: %d\n", *vector_begin(v));
//
//     for (int* it = vector_begin(v); it != vector_end(v); ++it) {
//         printf("%d ", *it);
//     }
//
//     puts("");
//
//     int* it = vector_begin(v);
//     int* end = vector_end(v);
//     while (it != end) {
//         printf("%d ", *it);
//         it = vector_next(v, it);
//     }
//
//     vector_free(v);
// }
