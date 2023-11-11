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

	cmd = strtok(command, " \n");
	*argcount = 0;
	while (cmd != NULL)
	{
		arguments[*argcount] = cmd;
		(*argcount)++;
		cmd = strtok(NULL, " ");
	}
	arguments[*argcount] = NULL;
	return (arguments[0]);
}
