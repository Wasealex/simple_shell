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
/*function prototype*/
void print_env(void);
#endif /*SHELL_H*/
