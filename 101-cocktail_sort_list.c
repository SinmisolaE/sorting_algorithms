#include "sort.h"

/**
 * cocktail_sort_list - sorts a list using cocktail sort
 * @list: the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *cur;
	int change;

	if (!list || !*list || !(*list)->next)
		return;
	cur = *list;
	change = 1;

	while (change)
	{
		change = 0;
		while (cur->next)
		{
			if (cur->n > cur->next->n)
			{
				swap_list(list, cur, cur->next);
				print_list(*list);
				change = 1;
			}
			else
				cur = cur->next;
		}
		while (cur->prev)
		{
			cur = cur->prev;
			if (cur->n > cur->next->n)
			{
				swap_list(list, cur, cur->next);
				print_list(*list);
				change = 1;
				cur = cur->prev;
			}
		}
	}

}

/**
 * swap_list - swaps list
 * @list: the head of list
 * @first: first node
 * @sec: second node
 */
void swap_list(listint_t **list, listint_t *first, listint_t *sec)
{
	listint_t *new;

	new = first->prev;
	if (new)
		new->next = sec;
	else
		*list = sec;
	sec->prev = new;
	first->next = sec->next;
	if (sec->next)
		sec->next->prev = first;
	sec->next = first;
	first->prev = sec;
}
