#include "../../include/collections/tuples.h"

static const size_t HASH_SIZE = 32;

int pair_eq(const Pair *a, const Pair *b) {
  return a->first == b->first && a->second == b->second;
}

int triple_eq(const Triple *a, const Triple *b) {
  return a->first == b->first && a->second == b->second && a->third == b->third;
}

int quad_eq(const Quad *a, const Quad *b) {
  return a->first == b->first && a->second == b->second &&
         a->third == b->third && a->fourth == b->fourth;
}

int quint_eq(const Quint *a, const Quint *b) {
  return a->first == b->first && a->second == b->second &&
         a->third == b->third && a->fourth == b->fourth && a->fifth == b->fifth;
}

uint32_t pair_hash(const Pair *a) {
  uint32_t first_hash = fnv_32(a->first);
  uint32_t second_hash = fnv_32(a->second);
  char buf[HASH_SIZE * 2];
  snprintf(buf, sizeof(buf), "(%ul, %ul)", first_hash, second_hash);

  return fnv_32(buf);
}

uint32_t triple_hash(const Triple *a) {
  uint32_t first_hash = fnv_32(a->first);
  uint32_t second_hash = fnv_32(a->second);
  uint32_t third_hash = fnv_32(a->third);
  char buf[HASH_SIZE * 3];
  snprintf(buf, sizeof(buf), "(%ul, %ul, %ul)", first_hash, second_hash,
           third_hash);

  return fnv_32(buf);
}

uint32_t quad_hash(const Quad *a) {
  uint32_t first_hash = fnv_32(a->first);
  uint32_t second_hash = fnv_32(a->second);
  uint32_t third_hash = fnv_32(a->third);
  uint32_t fourth_hash = fnv_32(a->fourth);
  char buf[HASH_SIZE * 4];
  snprintf(buf, sizeof(buf), "(%ul, %ul, %ul, %ul)", first_hash, second_hash,
           third_hash, fourth_hash);

  return fnv_32(buf);
}

uint32_t quint_hash(const Quint *a) {
  uint32_t first_hash = fnv_32(a->first);
  uint32_t second_hash = fnv_32(a->second);
  uint32_t third_hash = fnv_32(a->third);
  uint32_t fourth_hash = fnv_32(a->fourth);
  uint32_t fifth_hash = fnv_32(a->fifth);
  char buf[HASH_SIZE * 5];
  snprintf(buf, sizeof(buf), "(%ul, %ul, %ul, %ul, %ul)", first_hash,
           second_hash, third_hash, fourth_hash, fifth_hash);

  return fnv_32(buf);
}
