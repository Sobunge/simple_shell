#include "main.h"

/**
 * execute_command - a function that executes commands
 *
 * @input: input variable
 * @argv: argv argument
 */
void execute_command(char input[], char argv[])
{
	char *token;
	char *delim = " \t\n";
	int status = 0;  /* Default status for logical AND */
	char *next_command;

	/* Tokenize the input */
	token = strtok(input, delim);

	while (token != NULL)
	{

		if (strcmp(token, "|") == 0)
		{/* Handle pipe, execute the next command with piping */
			/* Extract the next command after the pipe symbol */
			next_command = strtok(NULL, delim);

			if (next_command != NULL)
			{

				printf("Second command: %s \n", next_command);
			} else
			{
				fprintf(stderr, "Error: Missing command after pipe '|'\n");
			}
		}

		 tokenizer(argv, status, token, delim);

		token = strtok(NULL, delim);
	}
}

