#include "main.h"

/**
 * execute_command - handles the execution of user commands
 *
 * @command: user command.
 *
 * Return: Nothing.
 */
void execute_command(char *command)
{
	/* Tokenize the command */
	char *args[MAX_INPUT_SIZE];
	int i = 0;
	char *token = strtok(command, " \t\n");

	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " \t\n");
	}
	args[i] = NULL;
	if (i > 0)
	{
		/* Check for built-in commans */
		if (strcmp(args[0], "exit") == 0)
			exit(0);
		else if (strcmp(args[0], "cd") == 0)
		{
			if (i > 1)
			{
				if (chdir(args[1]) != 0)
					perror("cd");
			}
			else
				fprintf(stderr, "cd: missing argument\n");
		}
		else
		{
			/* Fork and execute the command */
			pid_t child_pid = fork_and_execute(command);

			if (child_pid > 0)
			{
				/* Wats for child to finish */
				if (waitpid(child_pid, NULL, 0) == -1)
				{
					perror("waitpid");
					 exit(EXIT_FAILURE);
				}
			}
		}
	}
}
