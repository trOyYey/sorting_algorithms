#include "sort.h"

/*
 * cockktail_sort - function that sorts lists using cocktail sort
 * @list: pointer to doubly linked lists
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *p;
	int swapped;

	if (list == NULL || !*list || !(*list)->next)
		return;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
        	p = *list;
        	while (p->next)
		{
			if (p->n > p->next->n)
			{
				swap_list(list, p, p->next);
				swapped = 1;
				p = p->prev;
			}
			p = p->next;
		}
		if (!swapped)
            		break;

		swapped = 0;
		while (p->prev)
		{
			if (p->n < p->prev->n)
			{
				swap_list(list, p->prev, p);
				swapped = 1;
				p = p->next;
			}
			p = p->prev;
		}
	}
}

/*
 * swap - function that swiitches position of two lists
 * @a: pointer to list a
 * @b: pointer to list b
 */

void swap_list(listint_t **list, listint_t *a, listint_t *b)
{
	if (b->next)
		b->next->prev = a;
	if (a->prev)
		a->prev->next = b;
	else
		*list = b;
	a->next = b->next;
	b->next = a;
	b->prev = a->prev;
	a->prev = b;
	print_list(*list);
}
