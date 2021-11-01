% md5(1) Version 0.0.1 | libc | 2021-09-04 

NAME
====

**md5** — returns an MD5 hash of the buffer provided. 

SYNOPSIS
========

```c
#include "libc/include/crypto/md5.h"

MD5Result* md5(const char *initial_msg, size_t initial_len);
void md5_print(MD5Result *md5_hash);
```

DESCRIPTION
===========

The `md5()` function takes a `const char *` of the message to be hashed as its first parameter, and a second parameter that indicates the length of the message. 
It then returns an `MD5Result` struct, which contains 4 `uint32_t`s that contain the 128-bit hash in 32-bit components.


RETURN VALUE
============

The `md5()` function returns a pointer to an `MD5Result` struct, which contains 4 `uint32_t`s. This must be freed.

EXAMPLES
========

```c
MD5Result* md5_result = md5("hello", 5);
md5_print(md5_result); // prints 5d41402abc4b2a76b9719d911017c592
```

BUGS
====

See GitHub Issues: <https://github.com/takashiidobe/libc/issues>

AUTHOR
======

Takashi Idobe <mail@takashiidobe.com>

SEE ALSO
========

[**fnv(1)**](./fnv.md), [**adler32(1)**](./adler32.md) 

