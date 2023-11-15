#include "main.h"

int main(void) {
    char command[100];

    while (1) {
        /* Display the prompt */
        printf("#cisfun$ ");
        fflush(stdout);

        /* Read the command from the user */
        if (fgets(command, sizeof(command), stdin) == NULL) {
            /* Handle end of file (Ctrl+D or similar) */
            break;
        }

        /* Remove the newline character from the command */
        command[strcspn(command, "\n")] = '\0';

    }

    return 0;
}
