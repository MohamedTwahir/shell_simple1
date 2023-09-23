#include "shell.h"

/**
 * line_reader - will read the input string typed.
 *
 * @reader: return value of getline function
 * Return: a string input
 */
char *line_reader(int *reader)
{
	char *input = NULL;
	size_t bufsize = 0;

	*reader = getline(&input, &bufsize, stdin);
	return (input);
}
