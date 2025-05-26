/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juamanri <juamanri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:55:38 by juamanri          #+#    #+#             */
/*   Updated: 2025/05/26 09:05:11 by juamanri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*text;

	fd = open("1char.txt", O_RDONLY);
	while ((text = get_next_line(fd)))
	{
		printf("%s", text);
		free(text);
	}
	close(fd);

	printf("\n\n");
	fd = open("aaa.txt", O_RDONLY);
	while ((text = get_next_line(fd)))
	{
		printf("%s", text);
		free(text);
	}
	close(fd);

	printf("\n\n");
	fd = open("hola.txt", O_RDONLY);
	while ((text = get_next_line(fd)))
	{
		printf("%s", text);
		free(text);
	}
	close(fd);

	printf("\n\n");
	fd = open("juan.txt", O_RDONLY);
	while ((text = get_next_line(fd)))
	{
		printf("%s", text);
		free(text);
	}
	close(fd);

	printf("\n\n");
	fd = open("lines_around_10.txt", O_RDONLY);
	while ((text = get_next_line(fd)))
	{
		printf("%s", text);
		free(text);
	}
	close(fd);

	printf("\n\n");
	fd = open("lorem.txt", O_RDONLY);
	while ((text = get_next_line(fd)))
	{
		printf("%s", text);
		free(text);
	}
	close(fd);

	printf("\n\n");
	fd = open("numeros.txt", O_RDONLY);
	while ((text = get_next_line(fd)))
	{
		printf("%s", text);
		free(text);
	}
	close(fd);

	printf("\n\n");
	fd = open("salto.txt", O_RDONLY);
	while ((text = get_next_line(fd)))
	{
		printf("%s", text);
		free(text);
	}
	close(fd);

	printf("\n\n");
	fd = open("vacio.txt", O_RDONLY);
	while ((text = get_next_line(fd)))
	{
		printf("%s", text);
		free(text);
	}
	close(fd);
	return (0);
}
