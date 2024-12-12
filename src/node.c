#include "node.h"
#include "lib/error.c"
#include <stdlib.h>
#include <string.h>

struct Node *newPair(char *key, char *value) {
  if (!key || !value) {
    return NULL;
  }

  struct Node *pair = (struct Node *)malloc(sizeof(struct Node));

  if (!pair) {
    logError("Memory allocation error when allocating a new pair.");
    return NULL;
  }

  // used strdup just to be safe, a memory leak can occur in this case.
  pair->key = strdup(key);
  if (!pair->key) {
    free(pair);
    logError("Memory allocation error when allocating key for a new pair.");
    return NULL;
  }

  pair->value = strdup(value);
  if (!pair->value) {
    free(pair->key);
    free(pair);
    logError("Memory allocation error when allocating value for a new pair.");
    return NULL;
  }

  return pair;
}

int setNewValue(struct Node *pair, char *value) {
  if (!pair || !value) {
    logError("Invalid arguments provided to setNewValue.");
    return 0;
  }

  char *new_value = strdup(value);
  if (!new_value) {
    logError("Memory allocation error when allocating new value for a pair.");
    return 0;
  }

  free(pair->value);
  pair->value = new_value;
  return 1;
}

int deleteKVPair(struct Node *pair) {
  if (!pair) {
    logError("Invalid arguments provided to deleteKVPair.");
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
