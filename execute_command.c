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
	char *space = " ";
	char final_command[100];

	/* Tokenize the input */
	token = strtok(input, delim);

	while (token != NULL)
	{

		next_command = strtok(NULL, delim);

		if (next_command != NULL)
		{

			strcpy(final_command, token);
			strcat(final_command, space);
			strcat(final_command, next_command);
			execute_input(final_command, argv);

		} else
		{
			tokenizer(argv, status, token, delim);
		}

		token = strtok(NULL, delim);
	}

}

