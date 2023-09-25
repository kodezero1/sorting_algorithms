#include "sort.h"

/**
 * swap - Function that swaps two integers in an array.
 * @first: Pointer to the first integer to swap.
 * @second: Pointer to the second integer to swap.
 */
void swap(int *first, int *second)
{
	int temp;

	temp = *first;
	*first = *second;
	*second = temp;
}

/**
 * lomuto_partition - Function that orders a subset of an array of
 *			integers according to the Lomuto partition scheme
 *			(last element as pivot).
 *
 * @array: The array of integers.
 * @size: The size of the array.
 * @low: The starting index of the subset to order.
 * @high: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int *pivot, above, below;

	pivot = array + high;
	for (above = below = low; below < high; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - Function to implement the quicksort algorithm
 *		through recursion.
 *
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @low: The starting index of the array partition to order.
 * @high: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int low, int high)
{
	int partition_idx;

	if (high - low > 0)
	{
		partition_idx = lomuto_partition(array, size, low, high);
		lomuto_sort(array, size, low, partition_idx - 1);
		lomuto_sort(array, size, partition_idx + 1, high);
	}
}

/**
 * quick_sort - Function that sorts an array of integers in ascending order
 *              using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	lomuto_sort(array, size, 0, size - 1);
}
