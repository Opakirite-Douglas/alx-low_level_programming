#include "search_algos.h"

/**
 * linear_search - Func will search for a value in
 * an array of integers using the Linear search algorithm
 *
 * @array: The input array
 * @size: THe size of the array
 * @value: value to search in
 * Return: Always EXIT_SUCCESS
 */

int linear_search(int *array, size_t size, int value)
{
	size_t eye;

	if (array == NULL)
	{
		return (-1);
	}

	for (eye = 0; eye < size; eye++)
	{
		printf("Value checked array[%ld] = [%d]\n", eye, array[eye]);
		if (array[eye] == value)
		{
			return (eye);
		}
	}
	return (-1);
}
