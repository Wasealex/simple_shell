#include "shell.h"
/**
 *parser - parse code
 *@command: inputed command
 *@argcount: for multiple arguments
 *@arguments: save multiple arguments
 *Return: parsed code
 */
char *parser(char *command, int *argcount, char **arguments)
{
	char *cmd;

	while ((*command) == ' ')
	{
		command++;
	}

	cmd = strtok(command, " \n\t");/*space, newline, tab*/
	*argcount = 0;
	while (cmd != NULL)
	{
		arguments[*argcount] = cmd;
		(*argcount)++;
		cmd = strtok(NULL, " ");
	}
	arguments[*argcount] = NULL;/*null terminated for execve*/
	return (arguments[0]);/*return lines of input without space*/
}
