#include "shell.h"
/**
 *check_path - takes command as input and checks in path file
 *@cmd: check command
 *Return: full path or NULL
 */
char *check_path(const char *cmd)
{
	char *path;
	char *dir;
	char *full_path;
	char *path_copy;

	path = getenv("PATH");
	if (path == NULL)
	{
		return (NULL);
	}
	/*to have check path every loop*/
	path_copy = strdup(path);
	if (path_copy == NULL)
	{
		perror("strdup error");
		exit(EXIT_FAILURE);
	}
	/*initialize first directory*/
	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		/*to list the directories in an array*/
		full_path = malloc(strlen(dir) + strlen(cmd) + 2);
		if (full_path == NULL)
		{
			perror("malloc error");
			exit(EXIT_FAILURE);
		}
		strcpy(full_path, dir);
		strcat(full_path, "/");
		strcat(full_path, cmd);
		/*to check every separated files if is executable*/
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		/*to end the loop untill it reaches null*/
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
