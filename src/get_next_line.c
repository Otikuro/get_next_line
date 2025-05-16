/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juamanri <juamanri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:27:10 by juamanri          #+#    #+#             */
/*   Updated: 2025/05/16 12:21:37 by juamanri         ###   ########.fr       */
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

char	*ft_strjoin(char *s1, char *s2, int delete)
{
	int		i;
	int		s1_len;
	int		s2_len;
	char	*str;

	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc((s1_len + s2_len) + 1);
	if (!str)
		return (0);
	while (i < s1_len)
	{
		str[i] = s1[i];
		i++;
	}
	while (i < (s1_len + s2_len))
	{
		str[i] = s2[i - s1_len];
		i++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

int	ft_initialize_strings(char **stacked, char **buffer)
{
	*stacked = (char *)malloc(sizeof(char) * 1);
	if (*stacked == NULL)
		return (0);
	*buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (*buffer == NULL)
	{
		free(stacked);
		return (0);
	}
	*stacked[0] = '\0';
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*leftover = "";
	char		*stacked;
	char		*buffer;
	int			byte;
	int			line_len;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!ft_initialize_strings(&stacked, &buffer))
		return (NULL);
	stacked = ft_strjoin(stacked, leftover, 0);
	if (ft_get_line_len(stacked) != -1)
		buffer = stacked;
	while (ft_get_line_len(buffer) == -1)
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte == 0 && stacked[0] != '\0')
		{
			leftover = "";
			return (stacked);
		}
		else if (byte == 0)
		{
			free(stacked);
			free(buffer);
			return (NULL);
		}
		buffer[byte] = '\0';
		stacked = ft_strjoin(stacked, buffer, 1);
	}
	line_len = ft_get_line_len(buffer);
	leftover = ft_substr(buffer, line_len + 1, (byte - line_len));
	//free(buffer);
	return (ft_substr(stacked, 0, ft_get_line_len(stacked) + 1));
}
