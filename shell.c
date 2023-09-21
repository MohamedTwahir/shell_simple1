#include "shell.h"

/**
 * main - prints a prompt
 * Return: Always 0.
 */
int main(int ac, char **argv)
{
	//char *full_command = NULL, *copy_command = NULL;
	char *prompt = "#cisfun$ ";
	char *get_line = NULL, *get_line_copy = NULL; // stores the address of the buffer holding whatever was typed
	size_t n = 0;
	ssize_t reader;
	const char *delim = " \n";
	// char **argv;
	int tokens = 0;
	char *token;
	int i;

	(void)ac;

	// write(STDOUT_FILENO, prompt, strlen(prompt));

	// reader = getline(&get_line, &n, stdin);
	// get_line_copy = malloc(sizeof(char) * reader);

	while (1){
		write(STDOUT_FILENO, prompt, strlen(prompt));
		reader = getline(&get_line, &n, stdin);
		// write(STDOUT_FILENO, get_line, strlen(get_line));
		if (reader == -1){
			perror("Exiting shell...\n");
			return (-1);
		}
		get_line_copy = malloc(sizeof(char) * reader);
		if (get_line_copy == NULL){
			perror("memory allocation error");
			return (-1);
		}
		strcpy(get_line_copy, get_line);
		token = strtok(get_line, delim);

		while (token != NULL)
		{
			tokens++;
			token = strtok(NULL, delim);
		}
		tokens++;

		argv = malloc(sizeof(char *) * tokens);
		token = strtok(get_line_copy, delim);

		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);

			token = strtok(NULL, delim);
		}
		argv[i] = NULL;

		execmd(argv);
	}

	// 	get_line_copy = malloc(sizeof(char) * reader);
		// if (get_line_copy == NULL){
		// 	perror("tsh: memory allocation error");
		// 	return (-1);
		// }

		// strcpy(get_line_copy, get_line);
		// if (reader == -1){
		// 	perror("Exiting shell......\n");
		// 	return (-1);
		// }
		// else{

		// token = strtok(get_line, delim);

		// while (token != NULL){
		// 	tokens++;
		// 	token = strtok(NULL, delim);
		// }
		// tokens++;
		// argv = malloc(sizeof(char *) * tokens);

		// token = strtok(get_line_copy, delim);

		// for (i = 0; token != NULL; i++){
		// 	argv[i] = malloc(sizeof(char) * strlen(token));
		// 	strcpy(argv[i], token);

		// 	token = strtok(NULL, delim);
		// }
		// argv[i] = NULL;

		// write(STDOUT_FILENO, get_line, strlen(get_line));
		// free(argv);
		free(get_line);
		free(get_line_copy);
		// }
	// write(STDOUT_FILENO, prompt, strlen(prompt));
	// getline(&get_line, &n, stdin);
	// write(STDOUT_FILENO, get_line, strlen(get_line));

	// free(get_line);
   
	return (0);
}
