#include "hashTable.h"
#include "lib/error.c"
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 1024

struct HashTable *NewHashTable(char *name) {
  struct HashTable *table =
      (struct HashTable *)malloc(sizeof(struct HashTable));
  if (table == NULL) {
    logError("Memory allocation error when allocating a new hash table.");
    return NULL;
  }

  if (name == NULL) {
    table->name = NULL;
    logError("Invalid arguments provided to NewHashTable.");
    return NULL;
  }

  table->name = name;
  if (table->name == NULL) {
    free(table);
    logError("Memory allocation error when allocating owner for a new hash "
             "table.");
    return NULL;
  }

  table->size = TABLE_SIZE;
  table->count = 0;
  table->node = (struct Node **)calloc(TABLE_SIZE, sizeof(struct Node *));
  if (table->node == NULL) {
    free(table);
    return NULL;
  }

  return table;
}

int HashTableSet(struct HashTable *table, char *key, char *value) {
  unsigned int hashVal = hash(key);
  struct Node *node = table->node[hashVal];
  while (node != NULL) {
    if (strcmp(node->key, key) == 0) {
      node->value = value;
      return 1;
    }
    node = node->next;
  }

  node = (struct Node *)malloc(sizeof(struct Node));
  if (node == NULL) {
    return 0;
  }

  node->key = key;
  node->value = value;
  node->next = table->node[hashVal];
  table->node[hashVal] = node;
  table->count++;
  return 1;
}

char *HashTableGet(struct HashTable *table, char *key) {
  unsigned int hashVal = hash(key);
  struct Node *node = table->node[hashVal];
  while (node != NULL) {
    if (strcmp(node->key, key) == 0) {
      return node->value;
    }
    node = node->next;
  }
  return NULL;
}

int HashTableDelete(struct HashTable *table, char *key) {
  unsigned int hashVal = hash(key);
  struct Node *node = table->node[hashVal];
  struct Node *prev = NULL;
  while (node != NULL) {
    if (strcmp(node->key, key) == 0) {
      if (prev == NULL) {
        table->node[hashVal] = node->next;
      } else {
        prev->next = node->next;
      }
      free(node);
      table->count--;
      return 1;
    }
    prev = node;
    node = node->next;
  }
  return 0;
}

int FreeHashTable(struct HashTable *table) {
  for (int i = 0; i < table->size; i++) {
    struct Node *node = table->node[i];
    while (node != NULL) {
      struct Node *next = node->next;
      free(node->key);
      free(node->value);
      free(node);
      node = next;
    }
  }
  free(table->name);
  free(table->node);
  free(table);
  return 1;
}

int HashTableCount(struct HashTable *table) { return table->count; }

int HashTableSize(struct HashTable *table) { return table->size; }

/**
 * Generates a hash value for a given string key.
 * Uses Jenkins One-at-a-Time hash algorithm.
 * The function processes each character of the key
 * applies bit manipulation to generate a well distributed hash value.
 *
 * @param key The string key to hash
 * @return An unsigned integer hash value between 0 and TABLE_SIZE-1
 */
unsigned int hash(char *key) {
  unsigned int hash = 0;
  for (int i = 0; key[i]; i++) {
    hash += key[i];
    hash += (hash << 10);
    hash ^= (hash >> 6);
  }
  hash += (hash << 3);
  hash ^= (hash >> 11);
  hash += (hash << 15);
  return hash % TABLE_SIZE;
}
