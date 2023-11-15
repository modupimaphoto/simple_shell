#include "main.h"
/**
 * main - reads user input.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *input = NULL;
	size_t input_size = 0;
	ssize_t read;

	while (1)
	{
		display_prompt();

		read = getline(&input, &input_size, stdin);

		if (read == -1)
		{
			/* Handle CTRL + D */
			if (errno == ENOMEM)
			{
				perror("Error allocating memory");
				exit(EXIT_FAILURE);
			}
			printf("\nExiting shell.\n");
			free(input);
			exit(0);
		}

		/* Remove newline character */
		input[strspn(input, "\n")] = '\0';

		/* Execute the command */
		execute_command(input);
	}

	free(input);
	return (0);
}
