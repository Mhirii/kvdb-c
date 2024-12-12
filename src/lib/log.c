#include "log.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void logMessage(char *level, char *message, ...) {
  time_t rawtime;
  struct tm *timeinfo;
  char buffer[80];
  time(&rawtime);
  timeinfo = localtime(&rawtime);
  strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", timeinfo);

  printf("[%s]\t%s:\t%s", buffer, level, message);

  va_list args;
  va_start(args, message);
  char *arg = va_arg(args, char *);
  while (arg != NULL) {
    printf(" %s", arg);
    arg = va_arg(args, char *);
  }
  printf("\n");
  va_end(args);
}
