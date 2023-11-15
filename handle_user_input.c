#include "main.h"

#define MAX_INPUT_SIZE 100

/**
 * handle_user_input - a function that handles commands entered by user
 *
 *@input: input variable
 */
void handle_user_input(char *input, char argv[])
{
	int status;
	char command[MAX_INPUT_SIZE];
	char variable[MAX_INPUT_SIZE];
	char value[MAX_INPUT_SIZE];

	/* Remove the newline character from the input */
	input[strcspn(input, "\n")] = '\0';

	/* Checks if the input is exit */
	if (sscanf(input, "exit %d", &status) == 1)
	{
		exit_shell(status);
	} else if (strcmp(input, "exit") == 0)
		exit_shell(0);
	else if (strcmp(input, "env") == 0)
		print_environment();
	else if (sscanf(input, "%s %s %s", command, variable, value) == 3)
	{
		if (strcmp(command, "setenv") == 0)
		{
			set_environment_variable(variable, value);
		} else
		{
			execute_command(input, argv);
		}
	} else if (sscanf(input, "%s %s", command, variable) == 2)
	{
		if (strcmp(command, "unsetenv") == 0)
		{
			unset_environment_variable(variable);
		} else
		{

			execute_command(input, argv);
		}

	} else
		/* Execute command */
		execute_command(input, argv);
}
