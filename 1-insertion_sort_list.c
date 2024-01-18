#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of ints
 * @list: the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cur;
	listint_t *nod;
	listint_t *go;

	if (!*list || !list || !(*list)->next)
		return;
	go = *list;

	while (go)
	{
		cur = go;
		while (cur->prev && (cur->prev->n > cur->n))
		{
			nod = cur->prev;
			if (nod->prev)
				nod->prev->next = cur;
			else
				*list = cur;
			cur->prev = nod->prev;
			nod->next = cur->next;
			nod->prev = cur;
			if (cur->next)
				cur->next->prev = nod;
			cur->next = nod;
			print_list(*list);
		}
		go = go->next;
	}
}
