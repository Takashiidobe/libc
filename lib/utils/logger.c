#include "../../include/utils/logger.h"

static int start = 0;

Logger *new_logger(void (*log)(const char *), void (*err)(const char *)) {
  if (start != 0)
    return NULL;
  Logger *logger = malloc(sizeof(Logger));
  logger->_log = log;
  logger->_err = err;
  start++;
  return logger;
}
