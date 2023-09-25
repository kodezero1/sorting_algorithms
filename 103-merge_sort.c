#include "sort.h"

/**
 * merge_subarray - Merge two subarrays of an array.
 * @subarray: A subarray to merge.
 * @buffer: A buffer to store the merged subarray.
 * @front: The starting index of the first subarray.
 * @mid: The middle index of the subarray.
 * @back: The ending index of the subarray.
 */
void merge_subarray(int *subarray, int *buffer, size_t front, size_t mid,
                    size_t back)
{
    size_t i, j, k = 0;

    printf("Merging...\n[Left]: ");
    print_array(subarray + front, mid - front);

    printf("[Right]: ");
    print_array(subarray + mid, back - mid);

    for (i = front, j = mid; i < mid && j < back; k++)
        buffer[k] = (subarray[i] < subarray[j]) ? subarray[i++] : subarray[j++];
    for (; i < mid; i++)
        buffer[k++] = subarray[i];
    for (; j < back; j++)
        buffer[k++] = subarray[j];
    for (i = front, k = 0; i < back; i++)
        subarray[i] = buffer[k++];

    printf("[Done]: ");
    print_array(subarray + front, back - front);
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm through recursion.
 * @subarray: A subarray to sort.
 * @buffer: A buffer to store the sorted subarray.
 * @front: The starting index of the subarray.
 * @back: The ending index of the subarray.
 */
void merge_sort_recursive(int *subarray, int *buffer, size_t front, size_t back)
{
    size_t mid;

    if (back - front > 1)
    {
        mid = front + (back - front) / 2;
        merge_sort_recursive(subarray, buffer, front, mid);
        merge_sort_recursive(subarray, buffer, mid, back);
        merge_subarray(subarray, buffer, front, mid, back);
    }
}

/**
 * merge_sort - Sort an array of integers in ascending order using merge sort.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
    int *buffer;

    if (array == NULL || size < 2)
        return;

    buffer = malloc(sizeof(int) * size);
    if (buffer == NULL)
        return;

    merge_sort_recursive(array, buffer, 0, size);

    free(buffer);
}
