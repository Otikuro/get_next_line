/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juamanri <juamanri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:55:38 by juamanri          #+#    #+#             */
/*   Updated: 2025/05/19 11:25:28 by juamanri         ###   ########.fr       */
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

	fd = open("lorem.txt", O_RDONLY);
	while ((text = get_next_line(fd)))
	{
		printf("%s", text);
		free(text);
	}
	close(fd);
	return (0);
}
