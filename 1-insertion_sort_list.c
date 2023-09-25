#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list
 * using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * Description: Prints the list after each swap.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp;
	listint_t *current;
	listint_t *sorted = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (current = (*list)->next; current != NULL; current = temp)
	{
		temp = current->next;
		sorted = current->prev;
		while (sorted != NULL && current->n < sorted->n)
		{
			if (current->next != NULL)
				current->next->prev = sorted;
			sorted->next = current->next;
			current->next = sorted;
			if (sorted->prev != NULL)
				sorted->prev->next = current;
			current->prev = sorted->prev;
			sorted->prev = current;
			if (*list == sorted)
				*list = current;
			sorted = current->prev;
			print_list((const listint_t *)*list);
		}
	}
}
