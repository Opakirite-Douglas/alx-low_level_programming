#include "search_algos.h"

/**
 * binary_search - Func will seacrh for value in an int array using a binary
 * search algorithm.
 * @array: A pointer to first element of array to seach
 * @size: A number of elements in array
 * @value: value to search for
 *
 * Return: indeexx containing `value`, or -1 if `value` not found or
 * `array` is NULL
 */

int binary_search(int *array, size_t size, int value)
{
	int lLOw, mMid, hHigh;
	int exx;

	if (array == NULL)
	{
		return (-1);
	}

	lLOw = 0;
	hHigh = size - 1;

	while (lLOw <= hHigh)
	{
		mMid = (lLOw + hHigh) / 2;

		printf("Searching in array: ");
		for (exx = lLOw; exx <= hHigh; exx++)
			printf("%i%s", array[exx], exx == hHigh ? "\n" : ", ");

		if (array[mMid] < value)
			lLOw = mMid + 1;
		else if (array[mMid] > value)
			hHigh = mMid - 1;
		else
			return (mMid);
	}

	return (-1);
}
