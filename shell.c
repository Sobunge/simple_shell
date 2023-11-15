#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>

/* Function prototype */
int is_whitespace(const char *str);

/**
 * handle_input - handle input function
 *
 * @command: command argument
 */
void handle_input(char *command) {
    pid_t pid = fork();

    if (pid < 0) {
        perror("./shell");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        /* In the child process */
        char *args[2];
        args[0] = command;
        args[1] = NULL;

        /* Redirect standard output to the write end of the pipe */
        dup2(STDOUT_FILENO, STDOUT_FILENO);

        if (execve(command, args, environ) == -1) {
            /* If execve fails, print an error message */
            perror("./shell");
            exit(EXIT_FAILURE);
        }
    } else {
        /* In the parent process */
        int status;
        waitpid(pid, &status, 0);
    }
}

/**
 * is_whitespace - is white space function
 *
 * @str: command
 */
int is_whitespace(const char *str) {
    while (*str != '\0') {
        if (!isspace((unsigned char)*str)) {
            return 0;
        }
        str++;
    }
    return 1;
}

/**
 * main - main function
 * Return:
 * - Returns 0 upon successful execution.
 */
int main(void) {
    char command[100];

    while (1) {
        /* Display the prompt */
        printf("#cisfun$ ");
        fflush(stdout);

        if (fgets(command, sizeof(command), stdin) == NULL) {
            /* Handle end of file (Ctrl+D) */
            printf("\n");
            break;
        }

        /* Remove the newline character from the command */
        command[strcspn(command, "\n")] = '\0';

        if (command[0] == '\0' || is_whitespace(command)) {
            continue;
        } else {
            handle_input(command);
        }
    }

    return 0;
}

