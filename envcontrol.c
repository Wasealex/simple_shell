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
