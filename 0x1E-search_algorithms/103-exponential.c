#include "search_algos.h"

int binary_search_helper(int *array, int value,
			 size_t low, size_t high);
size_t min(size_t a, size_t b);

/**
 * min - To return minimum of two size_t values
 * @a: first
 *
 * @b: second value
 *
 * Return: `a` if lower or equal to `b`, `b` otherwise
 *
 */
size_t min(size_t a, size_t b)
{
	return (a <= b ? a : b);
}

/**
 * binary_search_helper - Func search for value in an in array using a
 * binary search algorithm, not guaranteed to return lowest index if `value`
 * appears twice in `array` (modified from `binary_search`)
 *
 * @array: A pointer to first element of array to search
 *
 * @value: The value to search for
 *
 * @low: starting index
 *
 * @high: ending index
 *
 * Return: index containing `value`, or -1 if `value` not found or
 * `array` is NULL
 *
 */

int binary_search_helper(int *array, int value,
			 size_t low, size_t high)
{
	size_t mMid, i;

	if (!array)
		return (-1);

	while (low <= high)
	{
		mMid = (low + high) / 2;
		printf("Searching in array: ");
		for (i = low; i <= high; i++)
			printf("%i%s", array[i], i == high ? "\n" : ", ");
		if (array[mMid] < value)
			low = mMid + 1;
		else if (array[mMid] > value)
			high = mMid - 1;
		else
			return ((int)mMid);
	}

	return (-1);
}

/**
 * exponential_search - Func search for value in a sorted array of int
 * using an exponential search algorithm
 *
 * @array: A pointer to 1st element of array to search
 *
 * @size: The number of elements in array
 *
 * @value: The value to search for
 *
 * Return: first index containing `value`, or -1 if `value` not found or
 * `array` is NULL
 *
 */

int exponential_search(int *array, size_t size, int value)
{
	size_t low, high, bound = 1;

	if (!array || size == 0)
		return (-1);

	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%lu] = [%d]\n",
		       bound, array[bound]);
		bound *= 2;
	}

	low = bound / 2;
	high = min(bound, size - 1);
	/* 'found' message generated even if array[high] < value */
	printf("Value found between indexes [%lu] and [%lu]\n", low, high);
	return (binary_search_helper(array, value, low, high));
}
