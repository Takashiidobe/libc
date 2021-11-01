#ifndef FNV_H
#define FNV_H

#include <stddef.h>
#include <stdint.h>

uint64_t fnv_64(const char *key);
uint32_t fnv_32(const char *key);

#endif
