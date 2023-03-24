#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 1024

int stack[STACK_SIZE];
int sp = 0; // stack pointer

void push(int value, int line_number)
{
	if (sp >= STACK_SIZE)
	{
		fprintf(stderr, "L%d: error: stack overflow\n", line_number);
		exit(EXIT_FAILURE);
	}
	stack[sp++] = value;
}
void pall(void)
{
	int i;
	for (i = sp - 1; i >= 0; i--)
	{
		printf("%d\n", stack[i]);
	}
}
int main(void)
{
	char opcode[10];
	int value, line_number = 0;
	while (scanf("%s", opcode) == 1)
	{
		line_number++;
		if (strcmp(opcode, "push") == 0)
		{
			if (scanf("%d", &value) != 1)
			{
				fprintf(stderr, "L%d: error: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			push(value, line_number);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall();
		}
		else
		{
			fprintf(stderr, "L%d: error: unknown opcode %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}
	return 0;
}
