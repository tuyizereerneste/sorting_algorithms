#include "sort.h"

/**
 * swaps - Function that swaps two integers
 * @a: first integer
 * @b: second integer
 */


void swaps(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Function that implements the
 * Lomuto partition scheme for Quick Sort
 * @array: The array to be partitioned
 * @first: first index
 * @last: last index
 * Return: The pivot index
 */

int lomuto_partition(int *array, int first, int last)
{
	int pivot, i, j;

	pivot = array[last];
	i = first - 1;
	for (j = first; j <= last - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swaps(&array[i], &array[j]);
		}
	}
	swaps(&array[i + 1], &array[last]);
	return (i + 1);
}

/**
 * lomuto_sort_recursive - Function that Recursively sorts
 * an array of integers using Quick Sort
 * @array: array to be sorted
 * @size: size of the array
 * @first: first index
 * @last: last index
 */

void lomuto_sort_recursive(int *array, int first, int last, size_t size)
{
	int p;

	if (first < last)
	{
		p = lomuto_partition(array, first, last);
		print_array(array, size);
		lomuto_sort_recursive(array, first, p - 1, size);
		lomuto_sort_recursive(array, p + 1, last, size);
	}
}

/**
 * quick_sort - Function that Sorts an array of integer
 * in ascending order using Quick Sort
 * @array: The array to be sorted
 * @size: The size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	lomuto_sort_recursive(array, 0, size - 1, size);
}
