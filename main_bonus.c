#include "./get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int	main(void)
{
	int		fd1;
	int		fd2;
	char	*text;

	fd1 = open("hola.txt", O_RDONLY);
	fd2 = open("numeros.txt", O_RDONLY);

	text = get_next_line(fd1);
	printf("Texto: %s", text);
	text = get_next_line(fd2);
	printf("Texto:  %s", text);
	text = get_next_line(fd1);
	printf("Texto:  %s", text);
	text = get_next_line(fd2);
	printf("Texto:  %s", text);

	close(fd1);
	close(fd2);
	return (0);
}
