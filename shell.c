#include "shell.h"

/**
 * main - prints a prompt
 * Return: Always 0.
 */
int main(int ac, char **argv)
{
	char *prompt = "#cisfun$ ";
	char *get_line; //stores the address of the buffer holding whatever was typed
	size_t n = 0;

	(void)ac; (void)argv;

	write(STDOUT_FILENO, prompt, strlen(prompt));
	getline(&get_line, &n, stdin);
	write(STDOUT_FILENO, get_line, strlen(get_line));

	free(get_line);
	return (0);
}
