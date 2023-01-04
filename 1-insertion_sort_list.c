#include "sort.h"

/**
  *
  */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *crtprev, *tmp;

	if (!list || !(*list))
		return;
	current = *list;
	while ((current = current->next))
	{
		tmp = current;
		while (tmp->prev && tmp->prev->n > tmp->n)
		{
			crtprev = tmp->prev;
			if (tmp->next)
				tmp->next->prev = crtprev;
			if (crtprev->prev)
				crtprev->prev->next = tmp;
			else
				*list = tmp;
			crtprev->next = tmp->next;
			tmp->prev = crtprev->prev;
			tmp->next = crtprev;
			crtprev->prev = tmp;
			print_list(*list);
		}
	}
}
