#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "main.h"

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
			break; // Exit the shell
		}
		
		execute_command_2(input);
	}

	return 0;
}
