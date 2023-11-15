#include "shell.h"
/**
 *set_environment_variable - sets environment variable
 *@variable: before the '='
 *@value: after the '='
 *Return: 0 if sucessful
 */
int set_environment_variable(const char *variable, const char *value)
{
	if (setenv(variable, value, 1) != 0)
	{
		dprintf(STDERR_FILENO, "Failed to set environment variable: %s\n"
			, variable);
		return (-1);
	}
	return (0);
}
/**
 *execute_setenv - execute the command for setenv in execute_command
 *@arguments: parsed arguments
 *Return: void
 */
void execute_setenv(char **arguments)
{
	if (arguments[1] == NULL || arguments[2] == NULL)
	{
		dprintf(STDERR_FILENO,
			"Invalid syntax. Usage: setenv VARIABLE VALUE\n");
		return;
	}
	set_environment_variable(arguments[1], arguments[2]);
}
/**
 *unset_environment_variable - deletes environment variable
 *@variable: to be deleted
 *Return: 0 if sucessfull
 */
int unset_environment_variable(const char *variable)
{
	if (unsetenv(variable) != 0)
	{
		dprintf(STDERR_FILENO, "Failed to unset environment variable: %s\n"
			, variable);
		return (-1);
	}
	return (0);
}
/**
 *execute_unsetenv - execute unsetenv command in execute_command
 *@arguments: parsed argument for unset
 *Return: void
 */
void execute_unsetenv(char **arguments)
{
	if (arguments[1] == NULL)
	{
		dprintf(STDERR_FILENO,
			"Invalid syntax. Usage: unsetenv VARIABLE\n");
		return;
	}
	unset_environment_variable(arguments[1]);
}
