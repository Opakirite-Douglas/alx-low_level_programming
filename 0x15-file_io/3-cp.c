#include "main.h"

void IO_CHECK(int My_stat, int opas_fd, char *filename, char The_mode);

/**
 * main - This is the main func and it simply
 * copies a file to another dest
 * @argv: This is the argument passed
 * @argc: This is the argument counter
 * Return: 1(SUCCESS) else exit
 */

int main(int argc, char *argv[])
{
	int src, dest, n_read = 1024, written, close_src, close_dest;
	unsigned int myMode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	char my_buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s", "Usage: cp file_from file_to\n");
		exit(97);
	}
	src = open(argv[1], O_RDONLY);
	IO_CHECK(src, -1, argv[1], 'O');
	dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, myMode);
	IO_CHECK(dest, -1, argv[2], 'W');

	while (n_read == 1024)
	{
		n_read = read(src, my_buffer, sizeof(my_buffer));
		if (n_read == -1)
		{
			IO_CHECK(-1, -1, argv[1], 'O');
		}
		written = write(dest, my_buffer, n_read);
		if (written == -1)
		{
			IO_CHECK(-1, -1, argv[2], 'W');
		}
	}
	close_src = close(src);
	IO_CHECK(close_src, src, NULL, 'C');
	close_dest = close(dest);
	IO_CHECK(close_dest, dest, NULL, 'C');

	return (0);
}

/**
 * IO_CHECK - Thisfunc simply checks whether a file
 * has the ability to be closed or opened
 * @filename: Just a pointer to the name of the file
 * @opas_fd: This represents the file descriptor
 * @The_mode: This represents close or open mode
 * @My_stat: This is the file descriptor of the file tosimply open
 * Return: Nothing
 */

void IO_CHECK(int My_stat, int opas_fd, char *filename, char The_mode)
{
	if (The_mode == 'C' && My_stat == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", Bens_fd);
		exit(100);
	}
	else if (The_mode == 'O' && My_stat == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
		exit(98);
	}
	else if (The_mode == 'W' && My_stat == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		exit(99);
	}
}
