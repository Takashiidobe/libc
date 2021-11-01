#include "../../include/utils/logger.h"
#include <assert.h>

void _log(const char *s) { assert(1); }
void _err(const char *s) { assert(1); }

void _log_fail(const char *s) { assert(0); }
void _err_fail(const char *s) { assert(0); }

void logger_tests() {
  Logger *logger = new_logger(_log, _err);

  assert(logger != NULL);
  logger->_log("Log this");
  logger->_err("error msg");

  Logger *logger2 = new_logger(_log_fail, _err_fail);
  assert(logger2 == NULL);

  free(logger);
}
