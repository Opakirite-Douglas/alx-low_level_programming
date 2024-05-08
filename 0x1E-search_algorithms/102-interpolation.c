#include "search_algos.h"

/**
 * interpolation_search - Func will search for value in a sorted array of int
 * using an interpolation search algorithm
 *
 * @array: A pointer to first element of array to search
 *
 * @size: A num of elements in array
 *
 * @value: value to search for
 *
 * Return: first index containing `value`, or -1 if `value` not found or
 * `array` is NULL
 *
 */

int interpolation_search(int *array, size_t size, int value)
{
	size_t lLow = 0;
	size_t hHigh = size - 1;
	size_t myPOS;

	if (!array)
		return (-1);

	while ((array[hHigh] != array[lLow]) &&
	       (value >= array[lLow]) && (value <= array[hHigh]))
	{
		myPOS = lLow + (((double)(hHigh - lLow) / (array[hHigh] - array[lLow]))
			    * (value - array[lLow]));
		printf("Value checked array[%lu] = [%d]\n", myPOS, array[myPOS]);
		if (array[myPOS] < value)
			lLow = myPOS + 1;
		else if (value < array[myPOS])
			hHigh = myPOS - 1;
		else
			return (myPOS);
	}
	if (value == array[lLow])
	{
		printf("Value checked array[%lu] = [%d]\n", lLow, array[lLow]);
		return (lLow);
	}
	myPOS = lLow + (((double)(hHigh - lLow) / (array[hHigh] - array[lLow]))
		     * (value - array[lLow]));
	printf("Value checked array[%lu] is out of range\n", myPOS);
	return (-1);
}
