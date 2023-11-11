#include "shell.h"
/**
 *main - entry point for shell command interpretor
 *@ac: argument count
 *@av: argument vector
 *Return: 0 if success
 */
int main(__attribute__((unused)) int ac, char **av)
{
	int nreads, argcount, counter = 0;
	char *command = NULL;
	size_t clen = 0;
	char *cmd = NULL;
	char *arguments[10];
	pid_t id;

	while (1)
	{
		/*reading the code*/
		counter++;
		printf("$ ");
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
		if (strncmp(command, "env", 3) == 0)
		{
			print_env();
			continue;
		}
		if (strlen(command) == 0)
			continue;
		/*parsing the command*/
		cmd = strtok(command, " \n");
		argcount = 0;
		while (cmd != NULL && argcount < 10)
		{
			arguments[argcount] = cmd;
			argcount++;
			cmd = strtok(NULL, " ");
		}
		arguments[argcount] = NULL;
		if (strncmp(command, "echo", 4) == 0)
		{
			arguments[0] = arguments[1];
		}
		/*executing the command*/
		id = fork();
		if (id == -1)
			perror("error");
		else if (id == 0)
		{
			if (execve(arguments[0], arguments, environ) == -1)
			{
				dprintf(STDERR_FILENO, "%s: %d: %s: not found\n", av[0], counter, arguments[0]);
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
