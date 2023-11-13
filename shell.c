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
    char full_path[256];

    while (1)
    {
        if (isatty(fileno(stdin)))
            printf("$ ");

        if (getline(&buff, &n, stdin) == -1)
        {
            fprintf(stderr, "Error reading input.\n");
            break;
        }

        if (command_exists(buff, full_path, (const char **)envp) == 1)
        {
            pid_t mypid = fork(); /* To create a child process */

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
                wait(&status);
                printf("back to the parent");
            }
        }
    }

    /* Cleanup allocated memory for 'buff' before exiting the program */
    free(buff);

    return 0;
}

