#include "sort.h"

void swap_integers(int *a, int *b);
void heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swap_integers - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_integers(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * heapify - Organize a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @base: The index of the base row of the tree.
 * @root: The root node of the binary tree.
 */
void heapify(int *array, size_t size, size_t base, size_t root)
{
    size_t left, right, largest;

    left = 2 * root + 1;
    right = 2 * root + 2;
    largest = root;

    if (left < base && array[left] > array[largest])
        largest = left;
    if (right < base && array[right] > array[largest])
        largest = right;

    if (largest != root)
    {
        swap_integers(array + root, array + largest);
        print_array(array, size);
        heapify(array, size, base, largest);
    }
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the heap sort algorithm.
 * Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
    int i;

    if (array == NULL || size < 2)
        return;

    for (i = (size / 2) - 1; i >= 0; i--)
        heapify(array, size, size, i);

    for (i = size - 1; i > 0; i--)
    {
        swap_integers(array, array + i);
        print_array(array, size);
        heapify(array, size, i, 0);
    }
}
