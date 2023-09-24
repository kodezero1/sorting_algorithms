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
 * bubble_sort - Function to sort an array of integers in ascending order.
 * @arr: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *arr, size_t size)
{
	size_t i, len = size;
	bool swapped = false;

	if (arr == NULL || size < 2)
		return;

	while (!swapped)
	{
		swapped = true;
		for (i = 0; i < len - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(arr + i, arr + i + 1);
				print_array(arr, size);
				swapped = false;
			}
		}
		len--;
	}
}
