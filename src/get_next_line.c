/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juamanri <juamanri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:27:10 by juamanri          #+#    #+#             */
/*   Updated: 2025/05/13 13:55:18 by juamanri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line.h"

char	*get_next_line(int fd)
{
	char	c;
	int		byte;
	int		line_len;

	if (fd == -1)
		return (0);
	else
	{
		line_len = 0;
		//El primer parametro es el file descriptor, elsegundo es la variable en el que se guarda la letra leida, el tercero es el numero de caracteres que se quieren leer.
		byte = read(fd, &c, 1);
		while (byte > 0)
		{
			line_len++;
			byte = read(fd, &c, 1);
			if (c == '\n')
				byte == 0;
		}
		return (line_len);
	}
}
