% fnv(1) Version 0.0.1 | libc | 2021-09-04 

NAME
====

**new_logger** — returns a Logger for logging.

SYNOPSIS
========

```c
#include "libc/include/utils/logger.h"

Logger *new_logger(void (*log)(const char *), void (*err)(const char *));
```

DESCRIPTION
===========

The `new_logger()` function takes a `log()` function and an `err()` function and returns a `Logger` struct.


RETURN VALUE
============

The `new_logger()` function returns a pointer to a logger or `NULL`.

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

