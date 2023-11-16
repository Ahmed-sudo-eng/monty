#include "monty.h"

/**
 * pop - a function that removes the top element of the stack
 * @head: points to the first element of the stack
 * @lineNumber: line number
 *
 * Return: Nothing
 */
void pop(stack_t **head, int lineNumber)
{
	stack_t *top = *head;
	stack_t *newTop = NULL;

	/* If stack is empty */
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", lineNumber);
		exit(EXIT_FAILURE);
	}
	/* If stack has just one element */
	if (top->next == NULL)
	{
		free(top);
		*head = NULL;
		return;
	}
	/* ELSE */
	while (top->next != NULL)
		top = top->next;
	newTop = top->prev;
	newTop->next = NULL;
	top->prev= NULL;
	free(top);
}
