#include "shell.h"

/**
 * _eputs - Prints An Input String
 * @str: The Sting To be Printed
 *
 * Return: nothing
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
 * _eputchar - Writes the Character c to stderr
 * @c: The Character To be Print
 *
 * Return: 1. On success.
 * On error, return -1, and errno is set appropriately.
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
 * _putfd - Writes The Character c to given fd
 * @c: The Character To Print
 * @fd: The Filedescriptor To Write To
 *
 * Return: 1. On success.
 * On error, return -1, and errno is set appropriately.
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
 * _putsfd - Prints Input String
 * @str: The String To Be Printed
 * @fd: The Filedescriptor To Write To
 *
 * Return: The Number Of Chars Put
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

