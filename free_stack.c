#include "monty.h"

/**
 * free_stack - a function that frees a stack
 * @head: a pointer that points to the first node
 *
 * Return: Nothing
 */
void free_stack(stack_t *head)
{
	stack_t *current = head;
	stack_t *tmp = NULL;

	while (current != NULL)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
}
