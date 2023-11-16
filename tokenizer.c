#include "main.h"

/**
 * tokenizer - a tokenizer
 *
 * @status: status variable
 * @argv: argv argument
 * @token: token argment
 * @delim: integer delim
 */
void tokenizer(char argv[], int status, char *token, char *delim)
{
	/* Check for command separator ';' */
	if (strcmp(token, ";") == 0)

		/* Reset status for the next command */
		status = 0;

	else if (strcmp(token, "&&") == 0)
	{
		/*
		* Logical AND, execute the next command
		* only if the previous one succeeded
		*/
		if (status == 0)
			status = 1; /* Set status for subsequent commands */
		else
		{
			/* Skip the next command */
			while (token != NULL && strcmp(token, ";") != 0)
				token = _strtok(NULL, delim);

			/* Reset status for the next command */
			status = 0;
		}
	} else if (strcmp(token, "||") == 0)
	{
		/* Logical OR, execute the next command only if the previous one failed */
		if (status != 0)
			status = 0; /* Set status for subsequent commands */
		else
		{
			/* Skip the next command */
			while (token != NULL && strcmp(token, ";") != 0)
				token = _strtok(NULL, delim);

			/* Reset status for the next command */
			status = 0;
		}
	} else
		execute_input(token, argv);

}
