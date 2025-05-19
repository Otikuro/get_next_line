/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juamanri <juamanri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:27:10 by juamanri          #+#    #+#             */
/*   Updated: 2025/05/19 11:17:16 by juamanri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line.h"

int	ft_get_line_len(char *str)
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

int	ft_initialize_strings(char **stacked, char **buffer)
{
	*stacked = ft_strdup("");
	*buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (*buffer == NULL)
	{
		free(stacked);
		return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*stacked;
	char		*buffer;
	int			byte;
	int			line_len;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	if (leftover == NULL)
		leftover = ft_strdup("");
	if (!ft_initialize_strings(&stacked, &buffer))
		return (NULL);
	stacked = ft_strjoin(stacked, leftover);
	free(leftover);
	if (ft_get_line_len(stacked) != -1)
		ft_strlcpy(buffer, stacked, (BUFFER_SIZE + 1));
	while (ft_get_line_len(buffer) == -1)
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte == 0 && stacked[0] != '\0')
		{
			leftover = ft_strdup("");
			free(buffer);
			return (stacked);
		}
		else if (byte == 0)
		{
			free(stacked);
			free(buffer);
			return (NULL);
		}
		buffer[byte] = '\0';
		stacked = ft_strjoin(stacked, buffer);
	}
	line_len = ft_get_line_len(buffer);
	leftover = ft_substr(buffer, line_len + 1, (byte - line_len));
	return (ft_substr(stacked, 0, ft_get_line_len(stacked) + 1));
}
