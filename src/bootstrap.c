#include "lib/error.h"
#include "os/fs.c"
#include "os/fs.h"

#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int bootstrap() {
  char *dir_name = "kvdb-c";

  char *dirCreated = create_data_dir(dir_name);
  if (strcmp(dirCreated, "ERROR") == 0) {
    newError("Bootstrap Failed");
    return 1;
  }

  char *path = malloc(strlen(dirCreated) + strlen("/initial") + 1);
  strcpy(path, dirCreated);
  strcat(path, "/initial");

  int fileCreated = touch(path);
  if (!fileCreated) {
    newError("Bootstrap Failed");
    return 0;
  };

  return 1;
}
