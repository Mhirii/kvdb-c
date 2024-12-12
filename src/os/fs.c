#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "../config.c"
#include "../lib/log.h"
#include "fs.h"

#ifdef _WIN32
#include <direct.h>
#define mkdir(path) _mkdir(path)
#else
#include <sys/stat.h>
#endif

int _mkdir(char *dir_name) {
  struct stat st = {0};
  if (stat(dir_name, &st) == 0) {
    return 1;
  }
  if (mkdir(dir_name, 0777) == -1) {
    logError("Error creating directory", dir_name);
    return 0;
  }
  logInfo("Created directory", dir_name);
  return 1;
}

char *create_data_dir(char *dir_name) {
  char *data_dir;
  static char path[PATH_MAX];

#ifdef _WIN32
  // Windows: Use %APPDATA% or %LOCALAPPDATA%
  data_dir = getenv("APPDATA");
  if (!data_dir) {
    data_dir = getenv("LOCALAPPDATA");
  }
#else
  // Linux/macOS: Use $XDG_DATA_HOME or $HOME/.local/share
  data_dir = getenv("XDG_DATA_HOME");
  if (!data_dir) {
    data_dir = getenv("HOME");
    if (data_dir) {
      data_dir = strcat(data_dir, "/.local/share");
    }
  }
#endif

  if (!data_dir) {
    logError("Error: Could not determine user data directory");
    return "ERROR";
  }

  snprintf(path, sizeof(path), "%s/%s", data_dir, dir_name);

  if (_mkdir(path))
    return path;
  logError("Error creating data directory", path);
  return "ERROR";
}
int touch(char *path) {
  struct stat st = {0};
  if (stat(path, &st) == 0) {
    return 1;
  }

  FILE *fp = fopen(path, "w");
  if (fp == NULL) {
    logError("Error creating file ", path);
    return 0;
  }

  fclose(fp);
  logInfo("Created file", path);
  return 1;
}
