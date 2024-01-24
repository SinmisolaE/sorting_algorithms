#include "sort.h"
void merge_recursion(int *array, int *buffer, size_t start, size_t last);
void merge_subarr(int *array, int *buffer, size_t start, size_t middle, size_t last);

void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (!array || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (!buffer)
		return;

	merge_recursion(array, buffer, 0, size);
	free(buffer);
}

void merge_recursion(int *array, int *buffer, size_t start, size_t last)
{
	size_t middle;

	if (last - start > 1)
	{
		middle = start + (last - start) / 2;
		merge_recursion(array, buffer, start, middle);
		merge_recursion(array, buffer, middle, last);
		merge_subarr(array, buffer, start, middle, last);
	}
}

void merge_subarr(int *array, int *buffer, size_t start, size_t middle, size_t last)
{
	size_t i, j, c = 0;

	printf("Merging...\n[Left]: ");
	print_array(&array[start], middle - start);

	printf("[Right]: ");
	print_array(&array[middle], last - middle);
	for (i = start, j = middle; i < middle && j < last; c++)
		buffer[c] = (array[i] < array[j]) ? array[i++] : array[j++];
	for (; i < middle; i++)
		buffer[c++]  = array[i];
	for (; j < last; j++)
		buffer[c++] = array[j];
	for (i = start, c = 0; i < last; i++)
		array[i] = buffer[c++];
	printf("[Done]:");
	print_array(&array[start], last - start);
}

