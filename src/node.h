
struct Node {
    struct Node *next;
    char *key;
    char *value;
};

/*!
 * Creates a new Node (key-value pair) structure
 *
 * @param key The key string for the pair
 * @param value The value string for the pair
 * @return Pointer to the newly created Node structure, or NULL if:
 *         - Either key or value is NULL
 *         - Memory allocation fails for the structure or strings
 */
struct Node *newPair(char *key, char *value);

/*!
 * Updates the value of an existing key-value pair
 *
 * @param pair Pointer to the Node structure to update
 * @param value The new value string to set
 * @return 1 if successful, 0 if:
 *         - Either pair or value is NULL
 *         - Memory allocation fails for the new value
 */
int setNewValue(struct Node *pair, char *value);

/*!
 * Deletes a key-value pair structure and frees all associated memory
 *
 * @param pair Pointer to the Node structure to delete
 * @return 1 if deletion was successful, 0 if pair was NULL
 */
int deleteKVPair(struct Node *pair);
