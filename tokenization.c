/**
 * line_divider - tokenizes the input string
 *
 * @input: input string
 * Return: splitted string
 */
char **line_divider(char *input)
{
	size_t csize;
	size_t i;
	char **tokens;
	char *token;


	csize = BUFSIZER;
	tokens = malloc(sizeof(char *) * (csize));
	if (tokens == NULL)
	{
		perror("allocation error\n");
		exit(EXIT_FAILURE);
	}
	token = _strtok(input, DELIMIZER);
	tokens[0] = token;

	for (i = 1; token != NULL; i++)
	{
		if (i == csize)
		{
			csize += BUFSIZER;
			tokens = malloc(tokens, i, sizeof(char *) * csize);
			if (tokens == NULL)
			{
				perror("allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = _strtok(NULL, DELIMIZER);
		tokens[i] = token;
	}

	return (tokens);
}

