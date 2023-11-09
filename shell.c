#include "shell.h"
/**
 *main - entry point for shell command interpretor
 *
 *Return: 0 if success
 */
int main(void)
{
	int nreads, argcount;
	char *command = NULL;
	size_t clen = 0;
	char *cmd = NULL;
	char *arguments[10];
	pid_t id;

	while (1)
	{
		printf("($) ");
		nreads = getline(&command, &clen, stdin);
		if (nreads == -1)
		{
			perror("EOF");
		}
		if (command[nreads - 1] == '\n')
			command[nreads - 1] = '\0';
		if (strncmp(command, "exit", 4) == 0)
		{
			break;
		}
		cmd = strtok(command, " ");
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
			if (execve(command, arguments, NULL) == -1)
				perror("command not found");
		}
		else
		{
			wait(NULL);
			exit(1);
		}
	}
	return (0);
}
