#include "sort.h"

/**
 * swap - Swap two integers in an array.
 * @first: The first integer to swap.
 * @second: The second integer to swap.
 */
void swap(int *first, int *second)
{
	int tmp;

	tmp = *first;
	*first = *second;
	*second = tmp;
}

/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t interval, outer, inner;

	if (array == NULL || size < 2)
		return;

	interval = 1;
	while (interval < size / 3)
		interval = interval * 3 + 1;

	while (interval >= 1)
	{
		for (outer = interval; outer < size; outer++)
		{
			inner = outer;
			while (inner >= interval && array[inner - interval] > array[inner])
			{
				swap(array + inner, array + (inner - interval));
				inner -= interval;
			}
		}
		print_array(array, size);
		interval /= 3;
	}
}
