#include "shell.h"

/**
 * execmd - finds commands and executes
 *
 * command: the command to be executed
 * Return: nothing to return
 * argv: arguments
 */
void execmd(char **argv)
{
	char *command = NULL;

	if (argv)
	{
		command = argv[0];
		if (execve(command, argv, NULL) == -1)
		{
			perror("./shell:\n");
		}
	}
}
