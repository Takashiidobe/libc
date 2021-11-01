#ifndef __LOGGER_H
#define __LOGGER_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Logger {
  void (*_log)(const char *);
  void (*_err)(const char *);
} Logger;

Logger *new_logger(void (*log)(const char *), void (*err)(const char *));

#endif
