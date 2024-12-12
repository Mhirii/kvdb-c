#include "main.h"
#include "config.c"
#include "hashTable.c"
#include "lib/error.c"
#include "lib/lib.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  // FIXME: handle main correctly
  struct HashTable *table = NewHashTable();
  char *key = "key1";
  char *value = "value1";
  HashTableSet(table, key, value);

  int choice = 99;
  while (choice != 0) {
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Get\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter key: ");
      char key[100];
      scanf("%s", key);
      printf("Enter value: ");
      char value[100];
      scanf("%s", value);
      HashTableSet(table, key, value);
      break;
    case 2:
      printf("Enter key: ");
      char key2[100];
      scanf("%s", key2);
      HashTableDelete(table, key2);
      break;
    case 3:
      printf("Enter key: ");
      newError("Something went wrong");
      char key3[100];
      scanf("%s", key3);
      char *value3 = HashTableGet(table, key3);
      printf("Value: %s\n", value3);
      break;
    case 4:
      break;
    default:
      printf("Invalid choice\n");
    }
  }
  return 0;
}
