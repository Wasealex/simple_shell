#include "shell.h"
/**
 *execute_command - get cmd and arguments and execute using execve
 *@cmd: cmd after parsed and checked
 *@arguments: other than cmds
 *@counter: counting errors
 *@av: argument vector for errors
 *Return: void
 */
void execute_command(char *cmd, char **arguments, int counter, char **av)
{
	if (strncmp(cmd, "setenv", 6) == 0)
		execute_setenv(arguments);
	else if (strncmp(cmd, "unsetenv", 8) == 0)
		execute_unsetenv(arguments);
	else
		execute_external(cmd, arguments, counter, av);
}
