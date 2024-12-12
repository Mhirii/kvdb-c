#include <stdlib.h>
#include <time.h>

char *get_timestamp() {
  time_t t;
  struct tm *tm;
  char *buf;
  t = time(NULL);
  tm = localtime(&t);
  buf = malloc(sizeof(char) * 20);
  strftime(buf, 20, "%Y-%m-%d_%H:%M:%S", tm);
  return buf;
}
