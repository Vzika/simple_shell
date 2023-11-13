#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// The use of strtok
// strtok breaks the string passed into bits(token) but the method of
// tokenlization
// it is able to break them by identifying delime, a form of separator

/*int main(void)
{
	char string[] = "Jesus, help us overcome this simple shell";
	char *delim = " ";
	char *token;

	token = strtok(string, delim);
	printf("%s\n", token);

	return (0);
}
*/

// using strokes to break and print all the string passed 
int main(void)
{
	char string[] = "Jesus, help us overcome this simple shell";
	char *delim = " \n";
	char *token;

	token = strtok(string, delim);

	while (token)
	{
		printf("%s\n", token);
		token = strtok(NULL, delim);
	}

	return (0);
}


// note that in the previous example, we used an array to store the string
// in this example, we use a string literal which only has read only, you cant
// write into it
// malloc was used here to create another string which can be edited by
// the strtok function
/*int main(void)
{
	char *string = "Jesus, help us overcome this simple shell";
	char *str_cpy;
	char *delim = " ";
	char *token;

	str_cpy = malloc(sizeof(char) * strlen(string));
	strcpy(str_cpy, string);

	token = strtok(str_cpy, delim);

	while (token)
	{
		printf("%s\n", token);
		token = strtok(NULL, delim);
	}

	return (0);
}
*/

//       ABANDONED PROJECT
// just trying to use argv in place of a string
// i havnt gotten it yet, ill get back to it
/* int main(int argc, char *argv[])
{
	char str[100];
	char *delim = " \n";
	char *token;
	int j;

	j = 0;
	while (j < argc)
	{
		str[j] = *argv[j];
		j++;
	}
	str[j] = '\0';

	j = 0;
	while (str[j])
	{
	printf("This are what wae copied into str: %s\n", str[j]);
	j++;
	}
	token = strtok(str, delim);

	while (token)
	{
		printf("%s\n", token);
		token = strtok(NULL, delim);
	}

	return (0);
} */
