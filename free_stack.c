#include "monty.h"

/**
 * free_stack - frees the stack
 * @top: stack
 *
 * Return: nothing
 */
void free_stack(stack_t *top)
{
	stack_t *tmp;

	while (top != NULL)
	{
		tmp = top;
		top = top->next;
		free(tmp);
	}
}

