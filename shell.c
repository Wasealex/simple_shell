#include "shell.h"
/**
 *main - entry point for shell command interpretor
 *@ac: argument count
 *@av: argument vector
 *Return: 0 if success
 */
int main(__attribute__((unused))int ac, char **av)
{
	int result, argcount, counter = 0;
	char *command = NULL;
	char *cmd = NULL;
	char *arguments[1024];
	char *full_path;
	int exit_status = 0;
	int terminal;
	int run_loop = 1;

	terminal = isatty(STDIN_FILENO);
	while (run_loop)
	{
		if (terminal)
		{
			printf("$ ");
		}
		result = process_command(&command);
		if (result < 0)
		{
			exit_status = -result;
			break;
		}
		if (result == 0)
		{
			break;
		}
		else if (result == 1)
		{
			free(command);
			continue;
		}
		else if (result == 2)
		{
			counter++;/*count the loop for errors*/
			cmd = parser(command, &argcount, arguments);
			if (cmd == NULL)
			{
				free(command);
				continue;
			}
			else
			{
				full_path = check_path(cmd);/* Path Checking*/
				if (full_path != NULL)
				{
					cmd = full_path;
				}
			}
			execute_command(cmd, arguments, counter, av);
			free(full_path);
			free(command);
		}
	}
	free(command);
	exit(exit_status);
}
