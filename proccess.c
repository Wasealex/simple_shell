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
	if (nreads == -1 || command == NULL)
	{
		return (0);
	}
	trimmed_command = strstrip(*command);
	if (strlen(trimmed_command) == 0)
	{
		return (1);
	}
	if (strncmp(trimmed_command, "exit", 4) == 0)
	{
		free(trimmed_command);
		return (-1);
	}
	if (strncmp(trimmed_command, "env", 3) == 0)/*first 3 char env*/
	{
		print_env();
		return (1);
	}
	*command = trimmed_command;
	return (2);
}
