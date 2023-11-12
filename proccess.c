#include "shell.h"
/**
 *process_command - read command line then process it
 *@command: command to be processed
 *Return: command read or NULL for exit EOF
 */
int process_command(char **command)
{
	size_t bufsize = 0;
	ssize_t nreads;
	char *trimmed_command;

	nreads = getline(command, &bufsize, stdin);
	if (nreads == -1)
	{
		/*printf("\n");*/
		return (0);
	}
	trimmed_command = strstrip(*command);
	if (strlen(trimmed_command) == 0)
	{
		free(*command);
		return (0);
	}
	if (strncmp(trimmed_command, "exit", 4) == 0)
	{
		return (0);
	}
	free(*command);
	*command = trimmed_command;
	return (1);
}
