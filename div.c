#include "monty.h"

/**
 * f_div - divides the second top element of the stack by
 * the top element of the stack
 * @head: stack
 * @line_number: line number
 *
 * Return: nothing
 */
void f_div(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	int div, len = 0;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		fclose(bus.file);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	temp = *head;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(bus.file);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	temp = *head;
	div = temp->next->n / temp->n;
	temp->next->n = div;

	*head = temp->next;
	free(temp);
}

