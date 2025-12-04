#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY | O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	write(fd, "Hello World\n", 12);
	write(fd, "Second Line\n", 12);
	write(fd, "Third Line", 10);
	close(fd);

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file for reading");
		return (1);
	}

	printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);

	line = get_next_line(fd);
	printf("Line 1: |%s|", line);
	free(line);

	line = get_next_line(fd);
	printf("Line 2: |%s|", line);
	free(line);

	line = get_next_line(fd);
	printf("Line 3: |%s|\n", line);
	free(line);

	line = get_next_line(fd);
	printf("Line 4: |%s|\n", line);
	free(line);

	close(fd);
	unlink("test.txt");
	return (0);
}
