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
	char	*str;
	//int		byte;
	//int		line_len;

	if (fd == -1)
		return (NULL);
	else
	{
		//line_len = 0;
		str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (str == NULL)
			return (NULL);
		//El primer parametro es el file descriptor, el segundo es la variable en el que se guarda la letra leida,
		//el tercero es el numero de caracteres que se quieren leer.
		//byte = read(fd, &str, BUFFER_SIZE);
		read(fd, &str, BUFFER_SIZE);
/* 		while (byte)
		{
			line_len++;
			byte = read(fd, &str, 1);
			if (str == '\n')
				byte = 0;
		} */
		return (str);
	}
}
