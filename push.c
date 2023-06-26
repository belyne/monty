#include "monty.h"

/**
* f_push - function that adds node to the stack
* @head: double head pointer to the stack
* @counter: line count
*
* Return: nothing
*/
void f_push(stack_t **head, unsigned int counter)
{
	int i, m = 0, flag = 0;

	if (stage.arg)
	{
		if (stage.arg[0] == '-')
			m++;
		for (; stage.arg[m] != '\0'; m++)
		{
			if (stage.arg[m] > 57 || stage.arg[m] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(stage.file);
			free(stage.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(stage.file);
		free(stage.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	i = atoi(stage.arg);
	if (stage.lifi == 0)
		addnode(head, i);
	else
		addqueue(head, i);
}
