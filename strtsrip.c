#include "shell.h"
/**
 *strstrip - is a function that clears leading or trailing white space
 *@str: string to be processed
 *
 *Return: cleared string
 */
char *strstrip(const char *str)
{
	size_t length = strlen(str);
	size_t start = 0;
	size_t end = length - 1;
	size_t trimmed_length;
	char *trimmed_str;

	if (str == NULL)
		return (strdup(""));
	/* Find the first non-whitespace character from the start */
	while (start < length && (str[start] == ' ' || str[start] == '\t'))
	{
		start++;
	}
	/* Find the last non-whitespace character from the end */
	while (end > start && (str[end] == ' ' || str[end] == '\t'))
	{
		end--;
	}
	/* Allocate memory for the trimmed string */
	trimmed_length = end - start + 1;
	trimmed_str = malloc((trimmed_length + 1) * sizeof(char));
	if (trimmed_str == NULL)
	{
		return (NULL);
	}
	/* Copy the trimmed string */
	strncpy(trimmed_str, str + start, trimmed_length);
	trimmed_str[trimmed_length] = '\0';
	return (trimmed_str);
}
