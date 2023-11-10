#include "shell.h"
/**
 *print_env - prints current environment
 *
 *Return: void
 *
 */
void print_env(void)
{
	int i;

	for (i = 0; environ[i] != 0; i++)
		printf("%s\n", environ[i]);
}
