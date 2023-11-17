#include "main.h"

/**
 * check_pipe - a function to check pipe
 *
 * @pipe_position: pipe_position argument
 * @input: input argument
 */
void check_pipe(char *pipe_position, char input[])
{
	char *first_command;
	char *second_command;
	char *end;

	/* Split the command into two parts around the pipe character */
	pipe_position = '\0';
	first_command = input;
	second_command = pipe_position + 1;

	/* Remove leading and trailing spaces from the second command */
	while (*second_command == ' ' || *second_command == '\t')
	{
		second_command++;
	}

	end = second_command + strlen(second_command) - 1;

	while (end > second_command && (*end == ' ' || *end == '\t'))
	{
		*end-- = '\0';
	}

	/* Execute the commands using pipe */
	execute_piped_commands(first_command, second_command);

}
