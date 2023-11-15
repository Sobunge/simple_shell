#include "main.h"

/**
 * main - Entry point for a simple UNIX command-line interpreter.
 *
 * Description:
 * - Initializes an infinite loop to continuously prompt for
 *    and process user commands.
 * @argc: number of arguments
 * @argv: array of arguments
 * - Displays the "#cisfun$ " prompt.
 * - Reads user input into the 'input' array, removing the newline character.
 * - Forks a child process to execute the user's command and distinguishes
 *   between the parent and child processes using the 'pid' variable.
 * - In the child process, it attempts to execute the user's command
 *   using 'execve'.
 *   - The 'args' array is used to hold the command to execute
 *   and a 'NULL' pointer.
 *   - If 'execve' succeeds, the command is executed; otherwise,
 *   it prints an error message using 'perror' and exits the child
 *   process with an error code.
 * - In the parent process, it waits for the child process to complete
 *   using 'waitpid', ensuring that the parent waits for the
 *   child to finish execution before proceeding.
 * - The loop continues, displaying the prompt again, and the shell waits
 *   for the next user command.
 *
 * Return:
 * - Returns 0 upon successful execution.
 */

int main(int argc, char *argv[])
{
	char *input;

	if (argc > 1)
	{
		int i;

		for (i = 1; i < argc; i++)
		{
			handle_user_input(argv[i], argv[0]);
		}
	}

	while (1)
	{

		/* Display the prompt */
		printf("#cisfun$ ");
		fflush(stdout);

		input = custom_getline();

		if (input)
		{
			handle_user_input(input, argv[0]);
			free(input);
		} else
			break;


	}

	free(input);

	return (0);
}
