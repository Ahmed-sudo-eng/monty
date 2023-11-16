#include "monty.h"

/**
 * pall - a function used to print all stack elements
 * @head: a pointer that points to the first node
 *
 * Return: Nothing
 */
void pall(stack_t *head)
{
	stack_t *current = head;

	while (current->next != NULL)
		current = current->next;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->prev;
	}

}
