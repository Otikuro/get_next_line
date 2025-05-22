/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juamanri <juamanri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:27:10 by juamanri          #+#    #+#             */
/*   Updated: 2025/05/22 13:36:29 by juamanri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

int	ft_get_newline_index(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	ft_initialize(char **leftover, char **stacked, char **buffer, int fd)
{
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (0);
	if (*leftover == NULL)
		*leftover = ft_strdup("");
	if (*leftover == NULL)
		return (0);
	*stacked = ft_strdup(*leftover);
	if (*stacked == NULL)
		return (free(*leftover), *leftover = NULL, 0);
	*buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (*buffer == NULL)
		return (free(*leftover), free(*stacked),
			*leftover = NULL, *stacked = NULL, 0);
	(*buffer)[0] = '\0';
	if (ft_get_newline_index(*stacked) != -1)
		ft_strlcpy(*buffer, *stacked, BUFFER_SIZE);
	return (free(*leftover), *leftover = NULL, 1);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*stack;
	char		*buffer;
	char		*line;
	int			byte;

	byte = 0;
	if (!ft_initialize(&leftover, &stack, &buffer, fd))
		return (NULL);
	while (ft_get_newline_index(stack) == -1)
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte == 0 && stack[0] != '\0')
		{
			leftover = ft_strdup("");
			return (free(buffer), buffer = NULL, stack);
		}
		else if (byte == 0)
			return (free(stack), free(buffer), stack = NULL, buffer = NULL, NULL);
		buffer[byte] = '\0';
		stack = ft_strjoin(stack, buffer);
	}
	leftover = ft_strdup(stack + ft_get_newline_index(stack) + 1);
	line = ft_substr(stack, 0, ft_get_newline_index(stack) + 1);
	return (free(stack), free(buffer), stack = NULL, buffer = NULL, line);
}
