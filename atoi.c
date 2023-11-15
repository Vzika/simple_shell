#include "shell.h"
/**
  * interactive - checks if the program is in interactive mode
  * @info: pointer to a structure
  *
  * Return: 1 if in interactive mode, 0 otherwise
  */

int interactiv(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
/**
  * is_delim - determines whether a character is a delimiter
  * @c: character to be checked
  * @delim: string containing delimiters
  *
  * Returns: 1 if true, 0 if false
  */

int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *_isalpha - checks for alphabetic character
 *@c: The character to input
 *Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
  * _atoi - converts a string to an integer
  * @s: string input to convert
  *
  * Returns: 0 if no numbers are present in the string, else returns the converted number
  */

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

