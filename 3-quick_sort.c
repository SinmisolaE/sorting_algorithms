#include "sort.h"

/**
 * quick_sort - sorts the array using quick sort
 * @array: the array
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	sort(array, 0, size - 1, size);
}

/**
 * sort - gives the low and high index
 * @array: the array
 * @low: the low index
 * high: the highest index
 * @size: size or length of array
 */
void sort(int *array, size_t low, size_t high, size_t size)
{
	size_t pi;

	if (low < high)
	{
		pi = partition(array, low, high, size);

		if (pi != low)
			sort(array, low, pi - 1, size);
		if (pi != high)
			sort(array, pi + 1, high, size);
	}
}

/**
 * partition - the implementation scheme
 * @array: array
 * @low: lowest index
 * @high: highest index
 * @size: size of array
 */
size_t partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot;
	size_t j;
	size_t i;

	i = low;
	pivot = array[high];

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				swap(&array[j], &array[i]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] > array[high])
	{
		swap(&array[i], &array[high]);
		print_array(array, size);
	}
	return (i);
}

/**
 * swap - swaps the elements
 * @a: first element
 * @b: second element
 */
void swap(int *a, int *b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}
