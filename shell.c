#include "shell.h"

int main(void)
{
    char *input = NULL;
    size_t len = 0;
    pid_t pid;

    while (1)
    {
        display_prompt();

        if (to_get_new_line(&input, &len, stdin) == -1)
        {
            /* Handle Ctrl+D */
            printf("\n");
            free(input);
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        pid = fork();

        if (pid == -1)
        {
            perror("Fork error");
            free(input);
            exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {
            char **args = (char **)malloc(2 * sizeof(char *));
            if (args == NULL)
            {
                perror("Memory allocation error");
                free(input);
                exit(EXIT_FAILURE);
            }

            args[0] = input;
            args[1] = NULL;

            if (execvp(args[0], args) == -1)
            {
                perror("Execution error");
                free(input);
                free(args);
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            int status;
            if (waitpid(pid, &status, 0) == -1)
            {
                perror("Waitpid error");
                free(input);
                exit(EXIT_FAILURE);
            }

            if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
            {
                fprintf(stderr, "Command not found or failed: %s\n", input);
            }
        }

        free(input);
    }

    return 0;
}

