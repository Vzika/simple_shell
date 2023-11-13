#include "shell.h"

/**
 * main - Entry point for the shell program.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 * @envp: Array of environment variables.
 *
 * Return: Always 0.
 */
int main(__attribute__((unused)) int argc, char **argv, char **envp)
{
	char *buff = NULL;
	size_t n = 0;
	char *full_path;
	pid_t mypid;
	size_t len;

    while (1)
    {
        if (isatty(fileno(stdin)))
            printf("$ ");

        if (getline(&buff, &n, stdin) == -1)
        {
            fprintf(stderr, "Error reading input.\n");
            break;
        }
	len = strlen(buff);
	if (buff[len - 1] == '\n')
	{
    		buff[len - 1] = '\0';  /*Replace newline with null terminator*/
	}
	if(strcmp(buff, "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
	full_path = command_exists(buff);
        if (full_path != NULL)
        {
		
         mypid = fork(); /* To create a child process */

            if (mypid == -1)
            {
                perror("fork");
            }
            else if (mypid == 0)
            {
                if (execve(full_path, argv, envp) == -1)
                {
                    perror("execve");
                    exit(EXIT_FAILURE); /* Exit child process on execve failure */
                }
            }
            else
            {
                int status;
		 waitpid(mypid, &status, 0);  /*Use waitpid for more control*/
                printf("Back to the parent\n");
            }
        }
    }

    /* Cleanup allocated memory for 'buff' before exiting the program */
    free(buff);
	free(full_path);

    return 0;
}

