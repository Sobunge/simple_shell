#ifndef FILE_MAIN
#define FILE_MAIN

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void execute_command(char input[])
void execute_command_2(const char *input);
void handle_path(char input[], char *args[], int i);
void path(char *token, char *args[]);

#endif