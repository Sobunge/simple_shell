#include "main.h"

/**
 * execute_piped_commands - a unction to execute piped commands
 *
 * @first_command: first command argument
 * @second_command: second command argument
 */
void execute_piped_commands(char *first_command, char *second_command)
{

	int pipe_fd[2];
	pid_t child_pid;

	if (pipe(pipe_fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	child_pid = fork();

	if (child_pid  == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{ /* Child process */
		close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
		execlp(first_command, first_command, NULL);
		perror("execlp");
		exit(EXIT_FAILURE);
	} else
	{/* Parent process */
		close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
		execlp(second_command, second_command, NULL);
		perror("execlp");
		exit(EXIT_FAILURE);
	}

}
