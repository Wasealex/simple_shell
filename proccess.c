#include "shell.h"
/**
 *process_command - read command line then process it
 *Return: command read or NULL for exit EOF
 */
char *process_command(void)
{
	char *command;
	size_t clen = 0;
	ssize_t nreads;

	nreads = getline(&command, &clen, stdin);
	if (nreads == -1)
	{
		printf("\n");
		return (NULL);
	}
	if (command[nreads - 1] == '\n')
	{
		command[nreads - 1] = '\0';
	}
	if (strncmp(command, "exit", 4) == 0)
	{
		return (NULL);
	}
	if (strlen(command) == 0)
	{
		return (NULL);
	}
	return (command);
}
