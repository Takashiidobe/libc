% adler32(1) Version 0.0.1 | libc | 2021-09-04 

NAME
====

**adler32** — returns an adler32 hash of the buffer provided. 

SYNOPSIS
========

```c
#include "libc/include/crypto/adler32.h"

uint32_t adler32(const char *key);
```

DESCRIPTION
===========

The `adler32()` function takes a `const char *` and returns a hashed version of its input.


RETURN VALUE
============

The `adler32()` function returns an `uint_32_t`.

EXAMPLES
========

```c
uint64_t first = fnv("Hello"); // 7201466553693376363UL;
uint64_t second = fnv("hello"); // 11831194018420276491UL;
```

BUGS
====

See GitHub Issues: <https://github.com/takashiidobe/libc/issues>

AUTHOR
======

Takashi Idobe <mail@takashiidobe.com>

SEE ALSO
========

[**fnv(1)**](./fnv.md)
