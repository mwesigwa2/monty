#include "monty.h"

/**
 * f_pint - prints the value at the top of the stack
 *
 * @head: stack
 * @line_number: line number
 *
 * Return: nothing
 */
void f_pint(stack_t **head, unsigned int line_number)
{
	if (*head)
		printf("%d\n", (*head)->n);
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		fclose(bus.file);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
}

