#include "monty.h"

/**
 * f_swap - swaps the top two elements of the stack
 * @head: stack
 * @line_number: line number
 * Return: nothing
 */
void f_swap(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;
	int len = 0;

	tmp = *head;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(bus.file);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	tmp = *head;
	*head = tmp->next;
	tmp->next = (*head)->next;
	tmp->prev = *head;
	(*head)->next = tmp;
	(*head)->prev = NULL;
}

