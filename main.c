#include "monty.h"

/**
 * main - interpreter for monty scripting language
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: On success (0) and (1) on failure
 */
int main(int argc, char *argv[])
{
	FILE *stream;
	char *line = malloc(1024);
	char *fileName;
	char *opcode = NULL;
	char *arg = NULL;
	stack_t *head = NULL;
	int lineNumber = 1;
	size_t i;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/* File opening */
	fileName = argv[1];
	stream = fopen(fileName, "r");
	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", fileName);
		exit(EXIT_FAILURE);
	}
	/* Main Programme */
	while ((fgets(line, 1024, stream)) != NULL)
	{
		opcode = strtok(line, " \n");
		if (opcode == NULL)
		{
			lineNumber++;
			continue;
		}
		if (line[0] == '#')
		{
			lineNumber++;
			continue;
		}
		arg = strtok(NULL, " \n");

		if (strlen(opcode) == 4 &&  opcode[0] == 'p' && opcode[1] == 'u'
				        && opcode[2] == 's' && opcode[3] == 'h')
		{
			/* Check if arg is NULL */
			if (arg == NULL)
			{
				fprintf(stderr, "L%d: usage: push integer\n", lineNumber);
				exit(EXIT_FAILURE);
			}
			/* Check if arg is not an integer */
			i = 0;
			while (i < strlen(arg))
			{
				if ((isdigit(arg[i])) == 0)
				{
					/* Exclude negative sign */
					if (arg[i] == '-')
					{
						i++;
						continue;
					}
					/* Print Error message and exit */
					fprintf(stderr, "L%d: usage: push integer\n", lineNumber);
					exit(EXIT_FAILURE);
				}
				i++;
			}
			/* Default */
			push(&head, atoi(arg));
		}
		else if (opcode[0] == 'p' && opcode[1] == 'a' && opcode[2] == 'l' && opcode[3] == 'l')
			pall(head);

		else if (strlen(opcode) == 4 && opcode[0] == 'p' && opcode[1] == 'i' && opcode[2] == 'n' 
				                                                     && opcode[3] == 't')
			pint(head, lineNumber);

		else if (strlen(opcode) == 3 && opcode[0] == 'p' && opcode[1] == 'o' && opcode[2] == 'p')
			pop(&head, lineNumber);

		else if (strlen(opcode) == 4 && opcode[0] == 's' && opcode[1] == 'w' && opcode[2] == 'a'
				                                                     && opcode[3] == 'p')
			swap(head, lineNumber);

		else if (strlen(opcode) == 3 && opcode[0] == 'a' && opcode[1] == 'd' && opcode[2] == 'd')
			add(head, lineNumber);

		else if (opcode[0] == 's' && opcode[1] == 'u' && opcode[2] == 'b')
			sub(head, lineNumber);

		else if (opcode[0] == 'd' && opcode[1] == 'i' && opcode[2] == 'v')
			divi(head, lineNumber);

		else if (opcode[0] == 'm' && opcode[1] == 'u' && opcode[2] == 'l')
			mul(head, lineNumber);

		else if (opcode[0] == 'm' && opcode[1] == 'o' && opcode[2] == 'd')
			mod(head, lineNumber);

		else if (opcode[0] == 'p' && opcode[1] == 's' && opcode[2] == 't' && opcode[3] == 'r')
			pstr(head);

		else if (opcode[0] == 'r' && opcode[1] == 'o' && opcode[2] == 't' && opcode[3] == '1')
			rot1(&head);

		else if (opcode[0] == 'p' && opcode[1] == 'c' && opcode[2] == 'h' && opcode[3] == 'a'
					  && opcode[4] == 'r')
			pchar(head, lineNumber);

		else if (opcode[0] == 'n' && opcode[1] == 'o' && opcode[2] == 'p')
		{
			lineNumber++;
			continue;
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", lineNumber, opcode);
			exit(EXIT_FAILURE);
		}

		lineNumber++;

	}

	free(line);
	free_stack(head);
	fclose(stream);
	return (0);
}
