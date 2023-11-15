#include "shell.h"
/**
 *execute_command - get cmd and arguments and execute using execve
 *@cmd: cmd after parsed and checked
 *@arguments: other than cmds
 *@counter: counting errors
 *@av: argument vector for errors
 *Return: void
 */
void execute_command(char *cmd, char **arguments, int counter, char **av)
{
	pid_t id;
	char *full_path;

	if (strcmp(cmd, "setenv") == 0)
	{
		if (arguments[1] == NULL || arguments[2] == NULL)
		{
			dprintf(STDERR_FILENO,
				"Invalid syntax. Usage: setenv VARIABLE VALUE\n"
				);
			return;
		}
		if (set_environment_variable(arguments[1], arguments[2]) == 0)
		{
			printf("Environment variable set: %s=%s\n"
			       , arguments[1], arguments[2]);
		}
	}
	else if (strcmp(cmd, "unsetenv") == 0)
	{
		if (arguments[1] == NULL)
		{
			dprintf(STDERR_FILENO,
				"Invalid syntax. Usage: unsetenv VARIABLE\n");
			return;
		}
		if (unset_environment_variable(arguments[1]) == 0)
		{
			printf("Environment variable unset: %s\n", arguments[1]);
		}
	}
	else
	{
		/*creating process for continues loops of command to be executed*/
		id = fork();
		/*if unable to create new process or EOF*/
		if (id == -1)
		{
			perror("error");
			exit(EXIT_FAILURE);
		}
		else if (id == 0)
		{
			/*check_path is used if the input is used a full path*/
			full_path = check_path(cmd);
			if (full_path != NULL)
			{
				if (execve(full_path, arguments, environ) == -1)
				{
					dprintf(STDERR_FILENO,
						"%s: %d: %s: not found\n"
						, av[0], counter, arguments[0]);
					exit(1);
				}
			}
			else/*if it used full path input use the cmd */
			{
				if (execve(cmd, arguments, environ) == -1)
				{
					dprintf(STDERR_FILENO
						, "%s: %d: %s: not found\n"
						, av[0], counter, arguments[0]);
					exit(1);
				}
			}
		}
		else
		{
			wait(NULL);
		}
	}
}
