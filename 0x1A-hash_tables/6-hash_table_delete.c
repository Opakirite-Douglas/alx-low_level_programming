#include "hash_tables.h"

/**
 * hash_table_delete - This func only deletes a hash table
 *
 * @ht: Just a pointer to a hash table
 *
 */

void hash_table_delete(hash_table_t *ht)
{
	hash_table_t *head = ht;
	hash_node_t *node, *tmp;
	unsigned long int eye;

	for (eye = 0; eye < ht->size; eye++)
	{
		if (ht->array[eye] != NULL)
		{
			node = ht->array[eye];
			while (node != NULL)
			{
				tmp = node->next;
				free(node->key);
				free(node->value);
				free(node);
				node = tmp;
			}
		}
	}
	free(head->array);
	free(head);
}
