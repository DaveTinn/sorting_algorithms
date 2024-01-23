#include "sort.h"
void swap_node(listint_t **list, listint_t *node1, listint_t *node2)
{
        if (node1->prev != NULL)
        {
                node1->prev->next = node2;
        }
	else
	{
		*list = node2;
	}
        if (node2->next != NULL)
        {
                node2->next->prev = node1;
        }
        node1->next = node2->next;
        node2->prev = node1->prev;
        node1->prev = node2;
        node2->prev = node1;
}
/**
 * cocktail_sort_list - Sorts a doubly linked list of ints in ascending order
 * @list: Pointer to the list of integers
 *
 * Return: Nothing
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head, *curr;
	int swap;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	do
	{
		swap = 0;
		head = *list;
		while (head->next != NULL)
		{
			if (head->n > head->next->n)
			{
				swap_node(list, head, head->next);
				swap = 1;
				print_list(*list);
				if (head->prev != NULL)
					head = head->prev;
			}
			else
			{
				head = head->next;
			}
		}
		if (swap == 0)
		{
			break;
		}
		swap = 0;
		curr = head;
		while (curr->prev != NULL)
		{
			if (curr->n < curr->prev->n)
			{
				swap_node(list, curr, curr->prev);
				swap = 1;
				print_list(*list);
				if (curr->next != NULL)
					curr = curr->next;
			}
			else
			{
				curr = curr->prev;
			}
		}
	}
	while (swap == 1 && head->next != NULL);
}
