#include "sort.h"
/**
 * insertion_sort_list - Sorts a doubly linked list of ints in ascending order
 * @list: list of integers
 *
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *temp, *idx;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	for (head = (*list)->next; head != NULL; head = head->next)
	{
		temp = head;

		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			idx = temp->prev;
			if (temp->next != NULL)
			{
				temp->next->prev = idx;
			}
			if (idx->prev != NULL)
			{
				idx->prev->next = temp;
			}
			temp->prev = idx->prev;
			idx->next = temp->next;
			temp->next = idx;
			idx->prev = temp;

			if (temp->prev == NULL)
			{
				*list = temp;
			}
			print_list(*list);
		}
	}
}
