#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: the array of integers
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	size_t n = size;
	int swap = 0;
	int c;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				c = array[j];
				array[j] = array[j + 1];
				array[j + 1] = c;
				print_array(array, n);
				swap = 1;
			}
		}
		if (swap != 1)
			break;
		swap = 0;
	}
}
