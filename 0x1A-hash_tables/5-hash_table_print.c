#include "hash_tables.h"

/**
 * hash_table_print - This func will print a hash table
 *
 * @ht: Simply a pointer to the hash table
 *
 * Description: value pairs are printed in the
 * way or order in which they appear in the array
 *
 */

void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *node;
	unsigned long int eye;
	unsigned char comma_flag = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (eye = 0; eye < ht->size; eye++)
	{
		if (ht->array[eye] != NULL)
		{
			if (comma_flag == 1)
				printf(", ");

			node = ht->array[eye];
			while (node != NULL)
			{
				printf("'%s': '%s'", node->key, node->value);
				node = node->next;
				if (node != NULL)
					printf(", ");
			}
			comma_flag = 1;
		}
	}
	printf("}\n");
}
