#include "shell.h"
/**
 *main - entry point for shell command interpretor
 *@ac: argument count
 *@av: argument vector
 *Return: 0 if success
 */
int main(__attribute__((unused)) int ac, char **av)
{
	int argcount, counter = 0;
	char *command = NULL;
	char *cmd = NULL;
	char *arguments[1024];
	char *full_path;

	while (1)
	{
		/*count the loop*/
		counter++;
		printf("$ ");
		/*read the command*/
		command = process_command();
		if (command == NULL)
			break;
		/*conditions*/
		if (strncmp(command, "env", 3) == 0)
		{
			print_env();
			continue;
		}

		/*parsing the command*/
		cmd = parser(command, &argcount, arguments);
		/* Path Checking */
		full_path = check_path(cmd);
		if (full_path != NULL)
		{
			cmd = full_path;
		}
		/*executing the command*/
		execute_command(cmd, arguments, counter, av);
	}
	free(command);
	return (0);
}
