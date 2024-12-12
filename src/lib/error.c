#include "error.h"
#include "log.c"
#include <stdlib.h>

// usage:
//  struct Error *err = newError("Something went wrong");
// Will log and exit with code 1

struct Error {
  char *message;

  void (*throw)(char *message);
};

void exitError(char *message) {
  printf("\n");
  logError(message);
  exit(1);
}

struct Error *newError(char *message) {
  struct Error *err = malloc(sizeof(struct Error));
  err->message = message;
  err->throw = exitError;
  err->throw(err->message);
  return err;
}
