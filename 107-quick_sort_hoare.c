#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_quick_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * hoare_partition - Partition a subarray of integers using the Hoare scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subarray to partition.
 * @right: The ending index of the subarray to partition.
 *
 * Return: The final pivot index.
 *
 * Description: Uses the last element of the subarray as the pivot.
 * Prints the array after each swap.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
    int pivot, above, below;

    pivot = array[right];
    for (above = left - 1, below = right + 1; above < below;)
    {
        do {
            above++;
        } while (array[above] < pivot);
        do {
            below--;
        } while (array[below] > pivot);

        if (above < below)
        {
            swap_ints(array + above, array + below);
            print_array(array, size);
        }
    }

    return above;
}

/**
 * hoare_quick_sort - Implement the quicksort algorithm using the Hoare scheme.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array to sort.
 * @right: The ending index of the array to sort.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_quick_sort(int *array, size_t size, int left, int right)
{
    int part;

    if (right - left > 0)
    {
        part = hoare_partition(array, size, left, right);
        hoare_quick_sort(array, size, left, part - 1);
        hoare_quick_sort(array, size, part, right);
    }
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending order
 *                    using the quicksort algorithm with the Hoare scheme.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    hoare_quick_sort(array, size, 0, size - 1);
}
