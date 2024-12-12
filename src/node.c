#include "node.h"
#include <stdlib.h>
#include <string.h>

struct Node *newPair(char *key, char *value) {
  if (!key || !value) {
    return NULL;
  }

  struct Node *pair = (struct Node *)malloc(sizeof(struct Node));

  if (!pair) {
    return NULL;
  }

  // used strdup just to be safe, a memory leak can occur in this case.
  pair->key = strdup(key);
  if (!pair->key) {
    free(pair);
    return NULL;
  }

  pair->value = strdup(value);
  if (!pair->value) {
    free(pair->key);
    free(pair);
    return NULL;
  }

  return pair;
}

int setNewValue(struct Node *pair, char *value) {
  if (!pair || !value) {
    return 0;
  }

  char *new_value = strdup(value);
  if (!new_value) {
    return 0;
  }

  free(pair->value);
  pair->value = new_value;
  return 1;
}

int deleteKVPair(struct Node *pair) {
  if (!pair) {
    return 0;
  }

  if (pair->key) {
    free(pair->key);
    pair->key = NULL;
  }

  if (pair->value) {
    free(pair->value);
    pair->value = NULL;
  }

  free(pair);
  return 1;
}
