#include "hash_tables.h"

/**
 * key_index - This func will get the index at
 * which a key/value pair shall be stored
 *
 * @key: Represents key to get the index of.
 *
 * @size: To rep size of the array of the hash table.
 *
 * Return: Key Index
 *
 * Description: Uses the djb2 algorithm.
 *
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
