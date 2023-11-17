#include "monty.h"

/**
 * mod - a fuction that computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @head: points to the first element
 * @lineNumber: line number
 *
 * Return: Nothing
 */
void mod(stack_t *head, int lineNumber)
{
	stack_t *current = head;
	stack_t *temp;

	/* If the stack contains less than two elements */
	if (head == NULL || head->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", lineNumber);
		exit(EXIT_FAILURE);
	}
	/* ELSE */
	while (current->next->next != NULL)
		current = current->next;
	/* Division by 0 Error */
	if (current->next->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", lineNumber);
		exit(EXIT_FAILURE);
	}
	current->n = current->n % current->next->n;
	temp = current->next;
	current->next = NULL;
	free(temp);
}
