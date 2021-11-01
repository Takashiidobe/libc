#include <stddef.h>
#include <stdint.h>

uint32_t djb2_hash(const char *address);

uint32_t djb2_str_hash(const char *str);
