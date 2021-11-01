% stdbool(1) Version 0.0.1 | libc | 2021-09-04 

NAME
====

**stdbool.h** — header file for boolean type and values.

SYNOPSIS
========

```c
#include "libc/include/stdbool.h"
```

DESCRIPTION
===========

The `<stdbool.h>` header shall define the following macros:

- `bool` Expands to `_Bool`.
- `true` Expands to the integer constant 1. 
- `false` Expands to the integer constant 0. 
- `__bool_true_false_are_defined` Expands to the integer constant 1.

An application may undefine and then possibly redefine the macros bool, true, and false.

BUGS
====

See GitHub Issues: <https://github.com/takashiidobe/libc/issues>

AUTHOR
======

Takashi Idobe <mail@takashiidobe.com>

SEE ALSO
========

None.
