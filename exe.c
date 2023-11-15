#include "main.h"
/**
 * execute_command - handles the execution of user commands
 * @command: user command.
 * Return: Nothing.
 */
void execute_command(char *command)
{
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
			pid_t child_pid = fork_and_execute(command);

			if (child_pid > 0)
			{
				if (waitpid(child_pid, NULL, 0) == -1)
				{
					perror("waitpid");
					 exit(EXIT_FAILURE);
				}
			}
		}
	}
}
