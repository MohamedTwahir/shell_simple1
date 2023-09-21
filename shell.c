#include "shell.h"

/**
 * main - prints a prompt
 * Return: Always 0.
 */
int main(int ac, char **argv)
{
	char *prompt = "#cisfun$ ";
	char *get_line = NULL; //stores the address of the buffer holding whatever was typed
	size_t n = 0;
	ssize_t reader;

	get_line = (char *)malloc(20);

	(void)ac; (void)argv;

	while (1){
		write(STDOUT_FILENO, prompt, strlen(prompt));
		reader = getline(&get_line, &n, stdin);
		// write(STDOUT_FILENO, get_line, strlen(get_line));
		if (reader == -1){
			// perror("Exiting shell...\n");
			return (-1);
		}

		write(STDOUT_FILENO, get_line, strlen(get_line));

		free(get_line);
	}
	// write(STDOUT_FILENO, prompt, strlen(prompt));
	// getline(&get_line, &n, stdin);
	// write(STDOUT_FILENO, get_line, strlen(get_line));

	// free(get_line);
   
	return (0);
}
