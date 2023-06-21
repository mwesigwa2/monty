#include "monty.h"

/**
 * f_mul - multiplies the second top element of the
 * stack with the top element of the stack
 * @head: stack
 * @line_number: line number
 *
 * Return: nothing
 */
void f_mul(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	int len = 0, mul;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		fclose(bus.file);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	temp = *head;
	mul = temp->next->n * temp->n;
	temp->next->n = mul;

	*head = temp->next;
	free(temp);
}

