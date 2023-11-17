#include "shell.h"

/**
 * _eputs - Prints a given string
 * @str: The string to be printed
 *
 * Return: Void
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - Outputs the character 'c' to the standard error (stderr)
 * @c: The character to be printed
 *
 * Return: Returns 1 upon success.
 * If an error occurs, -1 is returned, and errno is set accordingly.
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - Writes the character 'c' to the specified file descriptor (fd)
 * @c: The character to be printed
 * @fd: The file descriptor to write to
 *
 * Return: Returns 1 on success.
 * If an error occurs, -1 is returned, and errno is set accordingly.
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putsfd - Outputs a given string
 * @str: The string to be printed
 * @fd: The file descriptor to write to
 *
 * Return: The number of characters printed.
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}

