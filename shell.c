#include "shell.h"
/**
 *main - entry point for shell command interpretor
 *@ac: argument count
 *@av: argument vector
 *Return: 0 if success
 */
int main(__attribute__((unused))int ac, char **av)
{
	int argcount, counter = 0;
	char *command = NULL;
	char *cmd = NULL;
	char *arguments[1024];
	char *full_path;

	int terminal;

	terminal = isatty(STDIN_FILENO);

	while (1)
	{
		if (!terminal)
		{/*Read the command*/
			if (process_command(&command) == 0)
				break;
		}
		else
		{/*Prompt the user for a command*/
			printf("$ ");
			if (process_command(&command) == 0)
				break;
		}
		counter++;/*count the loop for errors*/
		/*conditions*/
		if (strncmp(command, "env", 3) == 0)/*first 3 char env*/
		{
			print_env();
			continue;
		}
		if (strlen(command) == 0)/*if only \n skip to next loop*/
		{
			continue;
		}
		/*parsing the command*/
		cmd = parser(command, &argcount, arguments);
		full_path = check_path(cmd);/* Path Checking wether ful*/
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
