#ifndef __VECTOR_H
#define __VECTOR_H

#include <assert.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "../math/math.h"

typedef struct Vector {
  size_t len;
  size_t capacity;
  int *items;
} Vector;

void vector_set_alloc(void *(malloc)(size_t), void *(realloc)(void *, size_t),
                      void (*free)(void *));

Vector *vector_new(const size_t len, ...);

void vector_free(Vector *v);

int vector_get(Vector *v, size_t index);

void vector_set(Vector *v, size_t index, int val);

int vector_empty(Vector *v);

void vector_push(Vector *v, int val);

int *vector_begin(Vector *v);

int *vector_end(Vector *v);

int *vector_next(Vector *v, int *it);

void vector_for_each(Vector *v, int (*fn)(int));

int vector_pop(Vector *v);

#endif
