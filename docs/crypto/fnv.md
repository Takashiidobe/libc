% fnv(1) Version 0.0.1 | libc | 2021-09-04 

NAME
====

**fnv** — returns an FNV hash of the buffer provided. 

SYNOPSIS
========

```c
#include "libc/include/crypto/fnv.h"

uint64_t fnv(const char *key);
```

DESCRIPTION
===========

The `fnv()` function takes a `const char *` and returns a hashed version of its input.


RETURN VALUE
============

The `fnv()` function returns an `uint_64_t`.

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

[**adler32(1)**](./adler32.md)

<https://en.wikipedia.org/wiki/Fowler-Noll-Vo_hash_function>

<https://datatracker.ietf.org/doc/html/draft-eastlake-fnv-17.html>
