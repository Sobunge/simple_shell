#ifndef FILE_MAIN
#define FILE_MAIN

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Declaring the external environ variable */
extern char **environ;

void execute_command(char input[]);
void handle_path(char input[], char *args[], int i);
void path(char *token, char *args[]);
void exit_shell(int status);
void print_environment(void);
char *custom_getline(void);
void handle_user_input(char *input);
void print_error(const char *message);
void set_environment_variable(const char *variable, const char *value);
void unset_environment_variable(const char *variable);
char *_strtok(char *str, const char *delim);

#endif
