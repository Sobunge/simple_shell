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
    char *saveptr;

    /* Tokenize the input based on ';' */
    token = strtok_r(input, ";", &saveptr);

    while (token != NULL)
    {
        /* Fork a child process for each command */
        pid_t pid = fork();

        if (pid < 0)
        {
            perror(argv);
            exit(1);
        }
        else if (pid == 0)
        {
            /* In the child process */
            char *args[64];
            int i = 0;

            handle_path(token, args, i, argv);

            /* If the loop completes, the command was not found in any directory in PATH */
            perror(argv);
            exit(1);
        }
        else
        {
            /* In the parent process */
            int status;
            waitpid(pid, &status, 0);
        }

        /* Get the next command */
        token = strtok_r(NULL, ";", &saveptr);
    }
}

