#include "monty.h"

/**
 * mul - a function that multiplies the second top element of the stack
 * with the top element of the stack
 * @head: point to the first element
 * @lineNumber: liner number
 *
 * Return: Nothing
 */
void mul(stack_t *head, int lineNumber)
{
	stack_t *current = head;
	stack_t *temp = NULL;

	/* If the stack contains less than two elements */
	if (head == NULL || head->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", lineNumber);
		exit(EXIT_FAILURE);
	}
	/* ELSE */
	while (current->next->next != NULL)
		current = current->next;
	current->n = current->n * current->next->n;
	temp = current->next;
	current->next = NULL;
	free(temp);
}
