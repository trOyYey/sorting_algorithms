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

	if (!list || !*list || !(*list)->next)
		return;

	for (currentNode = (*list)->next; currentNode; currentNode = currentNode->next)
	{
		nextNode = currentNode;
		while (nextNode->prev && nextNode->n < nextNode->prev->n)
		{
			tempNode = nextNode;
			previousNode = nextNode->prev, previousNode->next = tempNode->next;
			if (tempNode->next)
				tempNode->next->prev = previousNode;

			tempNode->next = previousNode, tempNode->prev = previousNode ->prev;
			previousNode->prev = tempNode;
				
			if (tempNode->prev)
				tempNode->prev->next = tempNode;
			else
				*list = tempNode;

			print_list(*list);
		}
	}
}

