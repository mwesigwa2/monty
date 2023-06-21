#include "monty.h"

/**
 * f_push - pushes an element to the stack
 * @head: stack
 * @line_number: line number
 *
 * Return: nothing
 */
void f_push(stack_t **head, unsigned int line_number)
{
	int n, x = 0;

	if (!bus.arg)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(bus.file);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (bus.arg[0] == '-')
			x++;

		for (; bus.arg[x] != '\0'; x++)
		{
			if (!isdigit(bus.arg[x]))
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				fclose(bus.file);
				free_stack(*head);
				exit(EXIT_FAILURE);
			}
		}
	}
	n = atoi(bus.arg);
	if (bus.st_or_que == 0)
		add_node_stack(head, n);
	else
		add_node_queue(head, n);
}
