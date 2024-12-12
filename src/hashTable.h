#include "node.h"

struct HashTable {
    int size;
    int count;
    struct Node **node;
};


/* Create a hash table. */
struct HashTable *NewHashTable();

/* Free a hash table. */
int FreeHashTable(struct HashTable *table);

/* Insert an item into the hash table. */
int HashTableSet(struct HashTable *table, char *key, char *value);

/* Find an item in the hash table. */
char *HashTableGet(struct HashTable *table, char *key);

int HashTableDelete(struct HashTable *table, char *key);

/* Return the number of items in the hash table. */
int HashTableCount(struct HashTable *table);

/* Return the size of the hash table. */
int HashTableSize(struct HashTable *table);

unsigned int hash( char *key);
