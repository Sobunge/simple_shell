#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * execute_command_2 - a function that executes commands
 *
 * @input: input variable
 */

void execute_command_2(const char *input) {
    pid_t child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        exit(1);
    }

    if (child_pid == 0) {
        char *args[32];
        int arg_count = 0;

        char *token = strtok((char *)input, " ");
        while (token != NULL) {
            args[arg_count] = token;
            arg_count++;
            token = strtok(NULL, " ");
        }
        args[arg_count] = NULL;

        execvp(args[0], args);
        perror("execvp");
        exit(1);
    } else {
        int status;
        waitpid(child_pid, &status, 0);
    }
}

int main(void) {
	char input[100];

	while (1) {
		printf(":) ");
		if (fgets(input, sizeof(input), stdin) == NULL) 
		{
			break;
		}
		input[strcspn(input, "\n")] = '\0';
		
		if (strcmp(input, "exit") == 0)
		{
			break; /*Exit the shell*/
		}
		
		execute_command_2(input);
	}

	return 0;
}
