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
	char *exit_string;
	int exit_return = 0;

	nreads = getline(command, &bufsize, stdin);
	if (nreads == -1 || command == NULL)
	{
		return (0);
	}
	trimmed_command = strstrip(*command);
	if (trimmed_command == NULL)
	{
		free(trimmed_command);
		return (1);
	}
	if (trimmed_command[0] == '\0')
	{
		free(trimmed_command);
		return (1);
	}
	if (strncmp(trimmed_command, "exit", 4) == 0)
	{
		exit_string = trimmed_command + 4;
		exit_return = find_exit(exit_string);
		free(trimmed_command);
		return (exit_return);
	}
	if (strncmp(trimmed_command, "env", 3) == 0)/*first 3 char env*/
	{
		print_env();
		free(trimmed_command);
		return (1);
	}
	free(*command);
	*command = trimmed_command;
	return (2);
}
