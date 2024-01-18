#include "sort.h"

/**
 * selection_sort - sorts array of ints in ascending oder
 * @array: the array
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;
	int temp;

	for (i = 0; i < size; i++)
	{
		min_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
			{
				min_index = j;
			}
		}
		if (min_index != i)
		{
			temp = array[min_index];
			array[min_index] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
}
