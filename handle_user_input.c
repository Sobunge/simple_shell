#include "main.h"

/**
 * handle_user_input - a function that handles commands entered by user
 *
 *@input: input variable
 */
void handle_user_input(char *input)
{
	/* Remove the newline character from the input */
	input[strcspn(input, "\n")] = '\0';

	/* Checks if the input is exit */
	if (strcmp(input, "exit") == 0)
		exit_shell();
	else if (strcmp(input, "env") == 0)
		print_environment();
	else
		/* Execute command */
		execute_command(input);

	free(input);

}
