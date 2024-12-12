#include "node.h"

struct HashTable {
    int size;
    int count;
    struct Node **node;
    char *name;
};


struct HashTable *NewHashTable(char *name);

int FreeHashTable(struct HashTable *table);

int HashTableSet(struct HashTable *table, char *key, char *value);

char *HashTableGet(struct HashTable *table, char *key);

int HashTableDelete(struct HashTable *table, char *key);

int HashTableCount(struct HashTable *table);

int HashTableSize(struct HashTable *table);

unsigned int hash( char *key);
