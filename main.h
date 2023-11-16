#ifndef FILE_MAIN
#define FILE_MAIN

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>

/* Declaring the external environ variable */
extern char **environ;

void execute_command(char input[], char argv[]);
void handle_path(char input[], char *args[], int i, char argv[]);
void path(char *token, char *args[], char argv[]);
void exit_shell(int status);
void print_environment(void);
char *custom_getline(void);
void handle_user_input(char *input, char argv[]);
void print_error(const char *message);
void set_environment_variable(const char *variable, const char *value, char argv[]);
void unset_environment_variable(const char *variable, char argv[]);
char *_strtok(char *str, const char *delim);
void execute_command(char input[], char argv[]);
void tokenizer(char argv[], int status, char *token, char *delim);
void execute_input(char *token, char argv[]);

#endif
