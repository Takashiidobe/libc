#include "../../include/crypto/adler32.h"

static const uint32_t MOD_ADLER = 65521;

uint32_t adler32(const char *key) {
  if (key == NULL)
    return 0;
  uint32_t a = 1;
  uint32_t b = 0;

  for (const char *p = key; *p; p++) {
    a = (a + *p) % MOD_ADLER;
    b = (b + a) % MOD_ADLER;
  }

  return (b << 16) | a;
}
