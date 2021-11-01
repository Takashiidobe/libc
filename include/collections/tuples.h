#ifndef TUPLES_H
#define TUPLES_H

#include "../crypto/fnv.h"
#include <stdio.h>

typedef struct {
  const void *first;
  const void *second;
} Pair;

typedef struct {
  const void *first;
  const void *second;
  const void *third;
} Triple;

typedef struct {
  const void *first;
  const void *second;
  const void *third;
  const void *fourth;
} Quad;

typedef struct {
  const void *first;
  const void *second;
  const void *third;
  const void *fourth;
  const void *fifth;
} Quint;

int pair_eq(const Pair *a, const Pair *b);
int triple_eq(const Triple *a, const Triple *b);
int quad_eq(const Quad *a, const Quad *b);
int quint_eq(const Quint *a, const Quint *b);

uint32_t pair_hash(const Pair *a);
uint32_t triple_hash(const Triple *a);
uint32_t quad_hash(const Quad *a);
uint32_t quint_hash(const Quint *a);

#endif
