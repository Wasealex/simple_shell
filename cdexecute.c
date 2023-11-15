#include "shell.h"
/**
 *execute_cd - all CD commands
 *@arguments: all arguments
 *Return: void
 */
void execute_cd(char **arguments)
{
	char *directory = NULL;
	int result;
	char current_directory[1024];

	directory = arguments[1];
	if (directory == NULL || strcmp(directory, "") == 0)
	{
		directory = getenv("HOME");
		if (directory == NULL)
		{
			dprintf(STDERR_FILENO, "cd: HOME variable empty\n");
			return;
		}
	}
	else if (strcmp(directory, "-") == 0)
	{
		directory = getenv("OLDPWD");
		if (directory == NULL)
		{
			dprintf(STDERR_FILENO, "cd: OLDPWD variable empty\n");
			return;
		}
	}
	result = chdir(directory);
	if (result != 0)
		perror("cd error");
	else
	{
		if (getcwd(current_directory, sizeof(current_directory)) != NULL)
		{
			set_environment_variable("PWD", current_directory);
			set_environment_variable("OLDPWD", getenv("PWD"));
		}
		else
			perror("cd error");
	}
}
