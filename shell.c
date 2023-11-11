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
		counter++;/*count the loop for errors*/
		printf("$ ");/*the prompt*/
		command = process_command();/*read the command and return null*/
		if (command == NULL)
			break;
		/*conditions*/
		if (strncmp(command, "env", 3) == 0)/*first 3 char match env*/
		{
			print_env();
			continue;
		}
		if (strlen(command) == 0)/*if newline only skip to next loop*/
		{
			continue;
		}
		/*parsing the command*/
		cmd = parser(command, &argcount, arguments);
		full_path = check_path(cmd);/* Path Checking for single or ful*/
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
