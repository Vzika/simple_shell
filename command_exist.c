#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

/**
 * command_exists - Check if a command exists in the PATH.
 * @cmd: The command to check.
 * @full_path: A buffer to store the full path of the command.
 * @envp: The environment variables.
 *
 * Return: NULL if nothing is found, or the path if found.
 */
char *command_exists(const char *cmd, char *full_path, const char **envp)
{
	const char *path = NULL;
	int exists;
	char *path_copy;
	char *token;
	char *full_command;
	struct stat st;
	full_command = (char*)malloc(sizeof(char)*10);

	/* Iterate through the environment variables to find PATH 
	   for (i = 0; envp[i] != NULL; i++)
	   {
	   if (strncmp(envp[i], "PATH=", 5) == 0)
	   {
	   path = envp[i] + 5;  //Extract the PATH value 
	   printf("%s\n", path);
	   break;
	   }
	   }

	   if (path == NULL)
	   {
	   fprintf(stderr, "PATH environment variable not found.\n");
	   return NULL; 
	   }*/
	path = getenv("PATH");
	path_copy = strdup(path);
	if (path_copy == NULL)
	{
		/*perror("strdup");*/
		return NULL; /* Error */
	}

	token = strtok(path_copy, ":");
	exists = 0;

	while (token != NULL && !exists)
	{
		strcpy(full_command, token);
		strcat(full_command, "/");
		strcat(full_command, cmd);

		/*snprintf(full_command, sizeof(full_command), "%s/%s", token, cmd);*/

		if (stat(full_command, &st) == 0 )
		{
			/*strcpy(full_path, full_command);*/
			return full_command;

			exists = 1;
		}
		
		else if (stat(full_command, &st) == -1)
		{
			free(full_command);
			token = strtok(NULL, ":");
			/*fprintf(stderr, "%s: No such file or directory\n", cmd);*/
			exists = 0;
		}

	}

	free(path_copy);

	if (!exists)
	{
		fprintf(stderr, "%s: command not found\n", cmd);
	}

	return full_command;
}

