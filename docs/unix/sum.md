% sum(1) Version 0.0.1 | libc | 2021-09-07

NAME
====

**sum** — checksum and count the blocks in a file 

SYNOPSIS
========

```sh
sum [OPTION]...  [FILE]...
```

DESCRIPTION
===========

Print checksum and block counts for each FILE.

With no FILE, or '-', read standard input.

```sh
-r use BSD sum algorithm, 1k blocks
-s, --sysv 
  use System V sum algorithm, with 512 byte blocks
-h, --help 
  display help and exit
-v, --version 
  output version information and exit
```

BUGS
====

See GitHub Issues: <https://github.com/takashiidobe/libc/issues>

AUTHOR
======

Takashi Idobe <mail@takashiidobe.com>

SEE ALSO
========

**false(1)** 
