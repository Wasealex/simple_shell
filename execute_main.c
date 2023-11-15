#include "shell.h"
/**
 *execute_external - get cmd and arguments and execute using execve
 *@cmd: cmd after parsed and checked
 *@arguments: other than cmds
 *@counter: counting errors
 *@av: argument vector for errors
 *Return: void
 */
void execute_external(char *cmd, char **arguments, int counter, char **av)
{
	pid_t id;
	char *full_path;

	id = fork();
	if (id == -1)
	{
		perror("error");
		exit(EXIT_FAILURE);
	}
	else if (id == 0)
	{
		full_path = check_path(cmd);
		if (full_path != NULL)
		{
			if (execve(full_path, arguments, environ) == -1)
			{
				dprintf(STDERR_FILENO,
					"%s: %d: %s: not found\n",
					av[0], counter, arguments[0]);
				free(full_path);
				exit(1);
			}
		}
		else
		{
			if (execve(cmd, arguments, environ) == -1)
			{
				dprintf(STDERR_FILENO,
					"%s: %d: %s: not found\n",
					av[0], counter, arguments[0]);
				exit(1);
			}
		}
	}
	else
	{
		wait(NULL);
	}
}
