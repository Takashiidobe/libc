#include <stdarg.h>
#include <stdio.h>

void put_size_t(const size_t s) {
  char buf[100];
  sprintf(buf, "%lu", s);
  for (size_t i = 0; buf[i] != '\0'; i++) {
    putchar(buf[i]);
  }
}

int my_printf(const char *fmt, ...) {
  const char *traverse;
  const char *s;
  size_t i;

  va_list arg;
  va_start(arg, fmt);
  for (traverse = fmt; *traverse != '\0'; traverse++) {
    switch (*traverse) {
    case '%': {
      if (*(traverse + 1) == 's') {
        s = va_arg(arg, const char *);
        fputs(s, stdout);
        traverse++;
        break;
      } else if (*(traverse + 1) == 'l' && *(traverse + 2) == 'u') {
        i = va_arg(arg, size_t);
        put_size_t(i);
        traverse += 2;
        break;
      } else {
        putchar(*traverse);
        break;
      }
    }
    default:
      putchar(*traverse);
      break;
    }
  }

  va_end(arg);
  return 0;
}

// int main() {
//   my_printf("Hi %s %s, random number: %lu\n", "my name", "is Sam", 2123000);
// }
