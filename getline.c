#include "shell.h"

/**
 * to_get_new_line - Custom implementation of getline.
 * @line: A pointer to the buffer storing the line.
 * @len: A pointer to the size of the buffer.
 * @fp: The file stream to read from.
 *
 * Return: The number of characters read, or -1 on failure or end of file.
 */
ssize_t to_get_new_line(char **line, size_t *len, FILE *fp)
{
    ssize_t nread;

    if (*line == NULL || *len == 0)
    {
        *len = MAX_INPUT_SIZE;
        *line = malloc(*len);
        if (*line == NULL)
        {
            perror("Memory allocation error");
            exit(EXIT_FAILURE);
        }
    }

    nread = getline(line, len, fp);

    if (nread == -1)
    {
        free(*line);
        *line = NULL;
    }

    return nread;
}

