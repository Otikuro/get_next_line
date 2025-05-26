#include "./get_next_line_bonus.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*text;

	// while ((text = get_next_line(1)))
	// {
	// 	printf("%s", text);
	// 	free(text);
	// }

	fd1 = open("hola.txt", O_RDONLY);
	fd2 = open("numeros.txt", O_RDONLY);
	fd3 = open("lines_around_10.txt", O_RDONLY);

	text = get_next_line(fd1);
	printf("Texto 1: %s", text);
	free(text);
	text = get_next_line(fd2);
	printf("Texto 2: %s", text);
	free(text);
	text = get_next_line(fd1);
	printf("Texto 1: %s", text);
	free(text);
	//
	text = get_next_line(fd2);
	printf("Texto 2: %s", text);
	free(text);
	text = get_next_line(fd2);
	printf("Texto 2: %s", text);
	free(text);
	text = get_next_line(fd2);
	printf("Texto 2: %s", text);
	free(text);
	text = get_next_line(fd2);
	printf("Texto 2: %s", text);
	free(text);
	text = get_next_line(fd2);
	printf("Texto 2: %s", text);
	free(text);
	text = get_next_line(fd2);
	printf("Texto 2: %s", text);
	free(text);
	text = get_next_line(fd2);
	printf("Texto 2: %s", text);
	free(text);
	text = get_next_line(fd2);
	printf("Texto 2: %s", text);
	free(text);
	text = get_next_line(fd2);
	printf("Texto 2: %s", text);
	free(text);
	//
	text = get_next_line(fd3);
	printf("\nTexto 3: %s", text);
	free(text);
	text = get_next_line(fd3);
	printf("Texto 3: %s", text);
	free(text);
	text = get_next_line(fd3);
	printf("Texto 3: %s", text);
	free(text);
	//
	text = get_next_line(fd1);
	printf("Texto 1: %s", text);
	free(text);
	text = get_next_line(fd1);
	printf("Texto 1: %s", text);
	free(text);

	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
