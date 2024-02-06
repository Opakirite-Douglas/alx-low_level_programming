#include "hash_tables.h"

/**
 * hash_table_create - This func will create a hash table.
 *
 * @size: Array size.
 *
 * Return: NULL (ERROR) else a pointer to the new hash table.
 *
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht;
	unsigned long int eye;

	ht = malloc(sizeof(hash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(hash_node_t *) * size);
	if (ht->array == NULL)
		return (NULL);
	for (eye = 0; eye < size; eye++)
		ht->array[eye] = NULL;

	return (ht);
}
