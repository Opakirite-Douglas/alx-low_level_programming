#include "search_algos.h"

int binary_search_recursion(int *array, int value,
			    size_t low, size_t high);

/**
 * binary_search_recursion - Func helps to `advanced_binary`,
 * recursively searches
 * for a value in an integer array
 * @array: pointer to first element of array to seach
 * @value: value to search for
 * @low: starting index in array
 * @high: ending index in array
 *
 * Return: index containing `value`, or -1 if `value` not found or
 * `array` is NULL
 */
int binary_search_recursion(int *array, int value,
			    size_t low, size_t high)
{
	size_t mMid, i;

	if (!array)
		return (-1);

	mMid = (low + high) / 2;
	printf("Searching in array: ");
	for (i = low; i <= high; i++)
		printf("%i%s", array[i], i == high ? "\n" : ", ");

	if (array[low] == value)
		return ((int)low);

	if (array[low] != array[high])
	{
		if (array[mMid] < value)
			return (binary_search_recursion(array, value,
							mMid + 1, high));
		if (array[mMid] >= value)
			return (binary_search_recursion(array, value,
							low, mMid));
	}

	return (-1);
}

/**
 * advanced_binary - Func search for a value in a sorted array of integers
 * using a binary search algorithm. Unlike `binary_search`, consistently
 * returns first appearance of `value` in array
 * @array: A pointer to first element of array to search
 * @size: The number of elements in array
 * @value: The value to search for
 *
 * Return: first index containing `value`, or -1 if `value` not found or
 * `array` is NULL
 */

int advanced_binary(int *array, size_t size, int value)
{
	size_t low = 0;
	size_t high = size - 1;

	if (!array)
		return (-1);

	return (binary_search_recursion(array, value, low, high));
}
