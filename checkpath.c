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
		return (NULL);
	path_copy = strdup(path);/*to have check path every loop*/
	if (path_copy == NULL)
	{
		perror("strdup error");
		exit(EXIT_FAILURE);
	}
	dir = strtok(path_copy, ":");/*initialize first directory*/
	while (dir != NULL)
	{
		full_path = malloc(strlen(dir) + strlen(cmd) + 2);/*list the dir*/
		if (full_path == NULL)
		{
			perror("malloc error");
			exit(EXIT_FAILURE);
		}
		strcpy(full_path, dir);
		strcat(full_path, "/");
		strcat(full_path, cmd);
		if (access(full_path, X_OK) == 0)/*if each file is executable*/
		{
			free(path_copy);
			return (full_path);
		}
		else
		{
			free(full_path);
		}
		dir = strtok(NULL, ":");/*to end the loop untill it reaches null*/
	}
	free(path_copy);
	return (NULL);
}
