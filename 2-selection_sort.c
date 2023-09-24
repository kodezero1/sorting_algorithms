#include "sort.h"

/**
 * swap_array_elements - Function to swap two integers in an array.
 * @first: Pointer to the first integer to swap.
 * @second: Pointer to the second integer to swap.
 */
void swap_array_elements(int *first, int *second)
{
	int temp;

	temp = *first;
	*first = *second;
	*second = temp;
}

/**
 * selection_sort - Function to sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *current_min;
	size_t i = 0, j;

	if (array == NULL || size < 2)
	{
		return;
	}

	while (i < size - 1)
	{
		current_min = array + i;

		j = i + 1;
		while (j < size)
		{
			if (array[j] < *current_min)
			{
				current_min = array + j;
			}
			j++;
		}

		if ((array + i) != current_min)
		{
			swap_array_elements(array + i, current_min);
			print_array(array, size);
		}
		i++;
	}
}
