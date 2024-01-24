#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void sort(int *array, size_t low, size_t high, size_t size);
size_t partition(int *array, size_t low, size_t high, size_t size);
void swap(int *a, int *b);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_list(listint_t **list, listint_t *first, listint_t *sec);
void counting_sort(int *array, size_t size);
int get_max(int *array, int size);
void merge_sort(int *array, size_t size);

#endif
