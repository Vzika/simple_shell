#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stddef.h>
//#define MAX_INPUT_SIZE 1024
//void display_prompt();
//ssize_t to_get_new_line(char **line, size_t *len, FILE *fp);
char *command_exists(const char *cmd, char *full_path, const char **envp);
#endif
