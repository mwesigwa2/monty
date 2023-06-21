#include "monty.h"

/**
 * f_pall - prints all the values on the stack,
 * starting from the top of the stack
 * @head: linked list stack
 * @line_number: line number
 *
 * Return: Nothing
 */
void f_pall(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	tmp = *head;
	if (tmp == NULL)
		return;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
