#include "main.h"

/**
 * create_file - This prog. simply create a file
 * @text_content: This is just a pointer to the content
 * @filename: This is just a pointer to the name of the file
 * Return: 1(SUCCESS), else -1(FAILURE)
 */

int create_file(const char *filename, char *text_content)
{
	int opas_fd;
	int rwr;
	int The_letters;

	if (!filename)
	{
		return (-1);
	}
	opas_fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (opas_fd == -1)
	{
		return (-1);
	}
	if (!text_content)
	{
		text_content = "";
	}

	for (The_letters = 0; text_content[The_letters]; The_letters++)
		;

	rwr = write(opas_fd, text_content, The_letters);

	if (rwr == -1)
	{
		return (-1);
	}
	close(opas_fd);

	return (1);
}
