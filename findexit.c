#include "shell.h"
/**
 *find_exit - returns for proccess_command exit status
 *@str: trimmed_command
 *
 *Return: 1 if illegal or exit num
 */
int find_exit(const char *str)
{
	int i, exit_num;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '-')
		{
			printf("./hsh: 1: exit: Illegal number:%s", str);
			return (1);
		}
		exit_num = atoi(str);
	}
	return (-exit_num);
}
