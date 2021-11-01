% uname(1) Version 0.0.1 | libc | 2021-09-07

NAME
====

**uname** — print system information 

SYNOPSIS
========

```sh
uname [OPTION(s)]...
```

DESCRIPTION
===========

Print system information. `uname` is the same as `uname -s`.

```sh
-a, --all
  print all information, in the following order:
              
-s, --kernel-name
  print the kernel name

-n, --nodename
  print the network node hostname

-r, --kernel-release
  print the kernel release

-v, --kernel-version
  print the kernel version

-m, --machine
  print the machine hardware name

-o, --operating-system
  print the operating system

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

**uname(2)** 
