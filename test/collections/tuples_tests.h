#include "../../include/collections/tuples.h"
#include "../../include/crypto/fnv.h"
#include <assert.h>

void tuple_test() {
  Pair p1 = {.first = "First"};
  Pair p2 = {.second = "First"};
  Pair p3 = {.first = &p1, .second = &p3};

  int one_hundred = 100;
  int two_hundred = 200;

  int one_hundred_ = 100;
  int two_hundred_ = 200;

  Pair p4 = {.first = &one_hundred, .second = &two_hundred};
  Pair p5 = {.first = &one_hundred_, .second = &two_hundred_};

  assert(pair_hash(&p1) != pair_hash(&p2));
  assert(pair_hash(&p3) != pair_hash(&p4));
  assert(pair_hash(&p4) == pair_hash(&p5));
}
