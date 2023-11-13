#include "shell.h"

/**
 * command_exists - Check if a command exists in the PATH.
 * @cmd: The command to check.
 * @full_path: A buffer to store the full path of the command.
 * @envp: The environment variables.
 *
 * Return: NULL if nothing is found, or the path if found.
 */
char *command_exists(char *cmd)
{
	const char *path = NULL;
	char *path_copy;
	char *token;
	char *full_command;
	struct stat st;
	 if (cmd == NULL)
	{

	        fprintf(stderr, "Invalid command\n");
        	return NULL;
    	}
	if(stat(cmd, &st)==0)
	{
		return cmd;
	}

	path = getenv("PATH");
	 if (path == NULL)
	{
        	fprintf(stderr, "PATH environment variable not found.\n");
        	return NULL;
    	}
	path_copy = strdup(path);

	full_command = (char *)malloc(strlen(path) + strlen(cmd) + 2);
	if (path_copy == NULL || full_command == NULL)
	{
        	perror("Memory allocation error");
        	free(path_copy);
        	free(full_command);
        	return NULL;
    	}

	token = strtok(path_copy, ":");

	while (token != NULL)
	{
		strcpy(full_command, token);
		strcat(full_command, "/");
		strcat(full_command, cmd);

		if (stat(full_command, &st) == 0 && (st.st_mode & S_IXUSR) != 0 )
		{
			free(path_copy);
			return full_command;

		}
		/*free(full_command);*/
		token = strtok(NULL, ":");

	}
	free(path_copy);
	free(full_command);
	/*Print an error message if the command is not found*/
	fprintf(stderr, "%s: command not found\n", cmd);

    return NULL;

}

