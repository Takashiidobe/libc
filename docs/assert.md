% assert(3) Version 0.0.1 | libc | 2021-09-05

NAME
====

**assert** — abort program if expression provided evaluates to false. 

**assert_eq** — abort program if both arguments are not equal. 

**assert_eqa** — abort program if both arguments as arrays are not equal. 

SYNOPSIS
========

```c
#include "libc/include/assert.h"

void assert(int expression);
void assert_eq(T x, T y);
void assert_eqa(T x[], const size_t x_len, T y[], const size_t y_len);
```

DESCRIPTION
===========

The `assert()` function takes an expression that evaluates to an `int` and aborts the program unless the `int` evaluates to 1. 

The `assert_eq()` function takes two generic arguments and aborts the program unless both sides are equal. 

The `assert_eqa()` function takes two generic arrays and aborts the program unless both arrays contain the same items. 

If `NDEBUG` is defined as a macro name before this header file is included, then all asserts do nothing.


DIAGNOSTICS
===========

The following diagnostic message is written to stderr if expression is false:

```c
"assertion \"%s\" failed: file \"%s\", line %d\n", "expression", __FILE__, __LINE__);
```

RETURN VALUE
============

No value is returned.

EXAMPLES
========

**assert**

```c
assert(10 == 10); // This does not abort the program.
assert(10 != 10); // This aborts the program.
```

The line above will print something like:

```fish
Assertion failed: 10 != 10 (main.c: main: 5)
fish: Job 1, './a.out' terminated by signal SIGABRT (Abort)
```

**assert_eq**

```c
assert_eq("hi", "hi"); // This does not abort the program.
assert_eq("", "hi"); // This aborts the program.
```

**assert_eqa**

```c
int a[] = {1, 2, 3};
int b[] = {1, 2, 3};
int c[] = {4, 5, 6};
assert_eqa(a, 3, b, 3); // This does not abort the program.
assert_eqa(b, 3, c, 3); // This aborts the program.
```

BUGS
====

See GitHub Issues: <https://github.com/takashiidobe/libc/issues>

AUTHOR
======

Takashi Idobe <mail@takashiidobe.com>

SEE ALSO
========

<https://man7.org/linux/man-pages/man3/assert.3.html>
