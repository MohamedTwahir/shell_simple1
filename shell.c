#include "shell.h"

/**
 * main - prints a prompt
 * Return: Always 0.
 */
int main(int ac, char **argv)
{
	char *prompt = "#cisfun$ ";
	char *get_line;
	size_t n = 0;

	(void)ac; (void)argv;

	printf("%s", prompt);
	getline(&get_line, &n, stdin);
	printf("%s\n", get_line);

	free(get_line);
	return (0);
}
