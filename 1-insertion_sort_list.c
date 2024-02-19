#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending order
 * @list: pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *prev;
	listint_t *next;
	
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	
	current = (*list)->next;
	while (current != NULL)
	{
		next = current->next;
		prev = current->prev;
		
		while (prev != NULL && prev->n > current->n)
		{
			prev->next = current->next;
			if (prev->next != NULL)
				prev->next->prev = prev;
			current->prev = prev->prev;
			current->next = prev;
			if (current->prev != NULL)
				current->prev->next = current;
			else
				*list = current;
			
			prev->prev = current;
			prev = current->prev;
			print_list(*list);
		}
		current = next;
	}
}

