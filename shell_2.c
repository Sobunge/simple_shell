#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - Entry point for a simple UNIX command-line interpreter.
 *
 * Description:
 * - Initializes an infinite loop to continuously prompt for
 *    and process user commands.
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
int main(void)
{
	char input[100];
	pid_t pid;

	while (1)
	{
		/* Display the prompt */
		printf("#cisfun$ ");

		/* Read the user's input */
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			break;
		}

		/* Remove the newline character from the input */
		input[strcspn(input, "\n")] = '\0';

		/* Fork a child process */
		pid = fork();

		if (pid < 0)
		{
			perror("Fork failed");
			exit(1);
		} else if (pid == 0)
		{
			/* In the child process */
			/* Execute the command using execve */
			/* Allocate memory for the args array */
			char *args[10];
			
			/*input token as first command*/
			args[0] = strtok(input, " ");
			
			int i = 1;
			while (i < 10 && (args[i] = strtok(NUL, " "))) 
			{
				i++;
			}

			args[i] = NULL;

			execve(args[0], args, NULL);
			/* If execve returns, it means the command was not found */
			perror("./shell");
			exit(1);
		} else
		{
			/* In the parent process */
			int status;

			waitpid(pid, &status, 0);
		}
	}

	return (0);
}
