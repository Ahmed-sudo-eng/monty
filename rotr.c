#include "monty.h"

/**
 * rotr - a function that rotates the stack to the bottom
 * @head: points to the first element
 *
 * Return: Nothing
 */
void rotr(stack_t *head)
{
	stack_t *top = head;

	while (top->next != NULL)
		top = top->next;

}
