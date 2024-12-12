#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define GRAY "\x1b[90m"
#define RESET "\x1b[0m"

#define logError(message, ...)                                                 \
  logMessage(RED "ERROR" RESET, message, ##__VA_ARGS__, NULL)
#define logInfo(message, ...)                                                  \
  logMessage(GREEN "INFO" RESET, message, ##__VA_ARGS__, NULL)
#define logWarning(message, ...)                                               \
  logMessage(YELLOW "WARNING" RESET, message, ##__VA_ARGS__, NULL)
#define logDebug(message, ...)                                                 \
  logMessage(GRAY "DEBUG" RESET, message, ##__VA_ARGS__, NULL)

void logMessage(char *level, char *message, ...);
