#include "main.h"

/**
 * read_textfile -This func will simply just read a text file
 * then print it to POSIX stdout
 * @letters: This represents the number of printed letters
 * @filename: This is just a pointer
 * Return: 0
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int opas_fd;
	char *opas_buff;
	ssize_t nrd, nwr;

	if (!filename)
	{
		return (0);
	}
	opas_fd = open(filename, O_RDONLY);

	if (opas_fd == -1)
	{
		return (0);
	}
	opas_buff = malloc(sizeof(char) * letters);
	if (opas_buff == NULL)
	{
		return (0);
	}

	nrd = read(opass_fd, opas_buff, letters);
	nwr = write(STDOUT_FILENO, opas_buff, nrd);

	close(opas_fd);
	free(opas_buff);

	return (nwr);
}
