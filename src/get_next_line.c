/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juamanri <juamanri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:27:10 by juamanri          #+#    #+#             */
/*   Updated: 2025/05/19 14:38:41 by juamanri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line.h"

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
		return (free(*leftover), 0);
	*buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (*buffer == NULL)
		return (free(*leftover), free(*stacked), 0);
	(*buffer)[0] = '\0';
	if (ft_get_newline_index(*stacked) != -1)
		ft_strlcpy(*buffer, *stacked, (BUFFER_SIZE + 1));
	return (free(*leftover), 1);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*stacked;
	char		*buffer;
	int			byte;
	int			line_len;

	byte = 0;
	if (!ft_initialize(&leftover, &stacked, &buffer, int fd))
		return (NULL);
	while (ft_get_newline_index(buffer) == -1)
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte == 0 && stacked[0] != '\0')
		{
			leftover = ft_strdup("");
			return (free(buffer), stacked);
		}
		else if (byte == 0)
			return (free(stacked), free(buffer), NULL);
		buffer[byte] = '\0';
		stacked = ft_strjoin(stacked, buffer);
	}
	line_len = ft_get_newline_index(buffer);
	leftover = ft_substr(buffer, line_len + 1, (byte - line_len));
	return (ft_substr(stacked, 0, ft_get_newline_index(stacked) + 1));
}
