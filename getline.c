#include "shell.h"

/**
 * get_input - Process user input, removing newline if present.
 * @buff: Pointer to the buffer storing user input.
 * @n: Size of the buffer.
 *
 * Return: 0 on success, -1 on failure.
 *
int get_input(char **buff, size_t *n) {
    ssize_t i;
    ssize_t read = getline(buff, n, stdin);

    if (read == -1) {
        perror("getline");
        return -1;
    }

    for (i = 0; i < read; i++) {
        if ((*buff)[i] == '\n') {
            (*buff)[i] = '\0';
            break;
        }
    }

    return 0;
}
*/
