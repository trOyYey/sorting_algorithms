#include "deck.h"


/**
 * card_id - find index of card
 * @node: pointer to head of the linked list
 * Return: id of the specified card
 */
int card_id(deck_node_t *node)
{
	int id = 0;
	const char *card = node->card->value;
	int kinds[4] = {0, 13, 26, 39};

	switch (card[0])
	{
		case 'A':
			id = 1;
			break;
		case 'J':
			id = 11;
			break;
		case 'Q':
			id = 12;
			break;
		case 'K':
			id = 13;
			break;
		default:
			id = card[0] - '0' + (card[1] == '\0' ? 0 : 9);
			break;
	}
	return (id + kinds[node->card->kind]);
}

/**
 * swap_deck - function that swiitches position of two lists
 * @a: pointer to list a
 * @b: pointer to list b
 * @list: pointer to linked lists
 */

void swap_deck(deck_node_t **list, deck_node_t *a, deck_node_t *b)
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
}

/**
 * sort_deck - function that sorts lists using cocktail sort
 * @deck: pointer to doubly linked lists
 */

void sort_deck(deck_node_t **deck)
{
	deck_node_t *p;
	int swapped;

	if (deck == NULL || *deck == NULL || !(*deck)->next)
		return;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		p = *deck;
		while (p->next)
		{
			if (card_id(p) > card_id(p->next))
			{
				swap_deck(deck, p, p->next);
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
			if (card_id(p) < card_id(p->prev))
			{
				swap_deck(deck, p->prev, p);
				swapped = 1;
				p = p->next;
			}
			p = p->prev;
		}
	}
}
