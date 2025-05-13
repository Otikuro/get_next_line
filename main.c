/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juamanri <juamanri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:55:38 by juamanri          #+#    #+#             */
/*   Updated: 2025/05/13 13:41:45 by juamanri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;

	fd = open("hola.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
/* 	while (text = get_next_line(fd))
	{
		printf("%d", text);
	} */
	close(fd);
	return (0);
}
