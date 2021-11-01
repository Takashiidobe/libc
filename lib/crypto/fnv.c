#include "../../include/crypto/fnv.h"
#include <string.h>

static const uint64_t FNV_64_OFFSET = 14695981039346656037UL;
static const uint64_t FNV_64_PRIME = 1099511628211UL;
static const uint32_t FNV_32_OFFSET = 2166136261U;
static const uint32_t FNV_32_PRIME = 16777619U;

uint64_t fnv_64(const char *key) {
  uint64_t hash = FNV_64_OFFSET;
  for (int i = 0; i < strlen(key); i++) {
    hash = hash ^ (key[i]);
    hash = hash * FNV_64_PRIME;
  }
  return hash;
}

uint32_t fnv_32(const char *key) {
  uint32_t hash = FNV_32_OFFSET;
  for (int i = 0; i < strlen(key); i++) {
    hash = hash ^ (key[i]);
    hash = hash * FNV_32_PRIME;
  }
  return hash;
}
