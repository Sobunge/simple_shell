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
    char *delim = " \t\n";
    int status = 0;  /* Default status for logical AND */

    /* Tokenize the input */
    token = strtok(input, delim);

    while (token != NULL)
    {
        /* Check for command separator ';' */
        if (strcmp(token, ";") == 0)
        {
            /* Reset status for the next command */
            status = 0;
        }
        else if (strcmp(token, "&&") == 0)
        {
            /* Logical AND, execute the next command only if the previous one succeeded */
            if (status == 0)
            {
                status = 1;  /* Set status for subsequent commands */
            }
            else
            {
                /* Skip the next command */
                while (token != NULL && strcmp(token, ";") != 0)
                {
                    token = strtok(NULL, delim);
                }
                /* Reset status for the next command */
                status = 0;
            }
        }
        else if (strcmp(token, "||") == 0)
        {
            /* Logical OR, execute the next command only if the previous one failed */
            if (status != 0)
            {
                status = 0;  /* Set status for subsequent commands */
            }
            else
            {
                /* Skip the next command */
                while (token != NULL && strcmp(token, ";") != 0)
                {
                    token = strtok(NULL, delim);
                }
                /* Reset status for the next command */
                status = 0;
            }
        }
        else
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
                int child_status;
                waitpid(pid, &child_status, 0);

                /* Update status based on the exit status of the command */
                if (WIFEXITED(child_status))
                {
                    status = WEXITSTATUS(child_status);
                }
            }
        }

        /* Get the next token */
        token = strtok(NULL, delim);
    }
}

