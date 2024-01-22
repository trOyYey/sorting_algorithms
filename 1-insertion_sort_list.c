#include "sort.h"

/**
 * insertion_sort_list - sort doubly linked lists with insertion sort method
 *
 * @list: pointer to head of the list
 *
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *currentNode, *nextNode, *tempNode, *previousNode;

	if (!list || !*list)
		return;

	for (currentNode = *list; currentNode->next; currentNode = currentNode->next)
	{
		nextNode = currentNode->next;
		if (nextNode->n < currentNode->n)
			currentNode = currentNode->prev;
		while (nextNode->prev && nextNode->n < nextNode->prev->n)
		{
			tempNode = nextNode;
			previousNode = nextNode->prev;
			if (tempNode->next)
				tempNode->next->prev = previousNode;
			previousNode->next = tempNode->next, tempNode->next = previousNode;
			if (previousNode->prev)
				previousNode->prev->next = tempNode;
			else
				*list = tempNode;
			tempNode->prev = previousNode->prev, previousNode->prev = tempNode;

			print_list(*list);
		}
	}
}

