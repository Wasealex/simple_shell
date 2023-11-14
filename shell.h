#ifndef SHELL_H
#define SHELL_H
/*MACROS*/
extern char **environ;

/*header files*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>
/*function prototype*/
void print_env(void);
char *parser(char *command, int *argcount, char **arguments);
char *check_path(const char *cmd);
void execute_command(char *cmd, char **arguments, int counter, char **av);
int process_command(char **);
char *strstrip(const char *);
int find_exit(const char *);
#endif /*SHELL_H*/
