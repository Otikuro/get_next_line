/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juamanri <juamanri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:55:38 by juamanri          #+#    #+#             */
/*   Updated: 2025/05/16 09:53:29 by juamanri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*text;

	fd = open("hola.txt", O_RDONLY);
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	while ((text = get_next_line(fd)))
	{
		printf("%s", text);
		free(text);
	}
	close(fd);
	return (0);
}
