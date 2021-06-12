#include "sort.h"

/**
 * insertion_sort_list - sort list with insertion sort algorithm
 * @list: list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *pn, *nn;

	if (list && *list && (*list)->next)
	{
		temp = (*list)->next;
		pn = temp->prev;
		nn = temp->next;

		while (temp)
		{
			if (temp->n < pn->n)
			{
				swap_insert(pn, temp, nn, list);
			}
			temp = nn;
			if (temp)
			{
				nn = temp->next;
				pn = temp->prev;
			}
		}
	}
}

/**
 * swap_insert - function that swaps integers with insertion form
 * @pn: linked list previous node
 * @tmp: node to be swapped
 * @nn: linked list nex node
 * @l: linked list head
 */
void swap_insert(listint_t *pn, listint_t *tmp, listint_t *nn, listint_t **l)
{

	while (pn && tmp->n < pn->n)
	{
		/* handle next node */
		if (nn)
			nn->prev = pn;

		/* handle temp node */
		tmp->next = pn;
		tmp->prev = pn->prev;

		/* handle prev node */
		if (pn->prev)
			(pn->prev)->next = tmp;
		pn->prev = tmp;
		pn->next = nn;

		/* reset comparison values */
		nn = pn;
		pn = tmp->prev;
		if ((*l)->prev)
			*l = (*l)->prev;
		print_list(*l);
	}
}
