#include "sort.h"

/**
 * counting_sort - sorts an array using counting sort
 * @array: the array
 * @size: length of array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, i, max;

	if (!array || size < 2)
		return;
	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return;
	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (!count)
	{
		free(sorted);
		return;
	}

	for (i = 0; i < (max + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]]++;
	for (i = 0; i < (max + 1); i++)
		count[i] += count[i - 1];

	print_array(count, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(count);
	free(sorted);
}

/**
 * get_max - gets max value
 * @array: the array
 * @size: length of array
 * Return: the greatest value
 */
int get_max(int *array, int size)
{
	int high, j;

	high = array[0];

	for (j = 1; j < size; j++)
	{
		if (array[j] > high)
			high = array[j];
	}
	return (high);
}
