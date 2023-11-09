#include "shell.h"
/**
 *main - entry point for shell command interpretor
 *
 *Return: 0 if success
 */
int main(__attribute__((unused)) int ac, char **av)
{
	int nreads, argcount;
	char *command = NULL;
	size_t clen = 0;
	char *cmd = NULL;
	char *arguments[10];
	pid_t id;

	while (1)
	{
		printf("#cisfun$ ");
		nreads = getline(&command, &clen, stdin);
		if (nreads == -1)
		{
			printf("\n");
			return (0);
		}
		if (strncmp(command, "exit", 4) == 0)
		{
			break;
		}
		if (strlen(command) == 0)
			continue;
		cmd = strtok(command, " \n");
		argcount = 0;
		while (cmd != NULL && argcount < 10)
		{
			arguments[argcount] = cmd;
			argcount++;
			cmd = strtok(NULL, " ");
		}
		arguments[argcount] = NULL;
		id = fork();
		if (id == -1)
			perror("error");
		else if (id == 0)
		{
			if (execve(arguments[0], arguments, NULL) == -1)
			{
				perror(av[0]);
				exit(1);
			}
		}
		else
		{
			wait(NULL);
		}
	}
	free(command);
	return (0);
}
