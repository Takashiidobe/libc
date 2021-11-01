#include "../../include/crypto/djb2.h"
#include <stdio.h>

static const uint32_t HASH_PRIME = 5381;

uint32_t djb2_hash(const char *address) {
  uint32_t hash = HASH_PRIME;
  for (size_t counter = 0; address[counter] != '\0'; counter++) {
    hash = ((hash << 5) + hash) + address[counter];
  }
  return hash;
}

uint32_t djb2_str_hash(const char *str) {
  uint32_t hash = HASH_PRIME;

  for (size_t counter = 0; str[counter] != '\0'; counter++) {
    hash = ((hash << 5) + hash) + str[counter];
  }

  return hash;
}
