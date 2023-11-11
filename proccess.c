#include "shell.h"
/**
 *process_command - read command line then process it
 *Return: command read or NULL for exit EOF
 */
char *process_command(void)
{
	char *command;
	size_t clen = 0;
	ssize_t nreads;

	nreads = getline(&command, &clen, stdin);/*interactive mode reading*/
	if (nreads == -1)/*if EOF or ctr+D is used*/
	{
		printf("\n");
		return (NULL);/*break from the loop after new line*/
	}
	if (command[nreads - 1] == '\n')/*to check the end for new line char*/
	{
		command[nreads - 1] = '\0';/*to change it to null*/
	}
	if (strncmp(command, "exit", 4) == 0)/*if the first 4 letter match exit*/
	{
		return (NULL);/*break on the loop*/
	}
	return (command);
}
