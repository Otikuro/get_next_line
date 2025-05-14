/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juamanri <juamanri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:27:10 by juamanri          #+#    #+#             */
/*   Updated: 2025/05/14 12:42:05 by juamanri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line.h"

int	ft_line_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
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
	return (str);
}

#include <stdio.h>


int	ft_initialize_strings(char **stacked, char **buffer)
{
	*stacked = (char *)malloc(sizeof(char) * 1);
	if (*stacked == NULL)
		return (0);
	*buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (*buffer == NULL)
		return (0);
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

	if (fd == -1)
		return (NULL);
	if (!ft_initialize_strings(&stacked, &buffer))
		return (NULL);
	printf("\tLeftover: %s", leftover);
	ft_strjoin(stacked, leftover);
	while (!ft_strchr(buffer, '\n'))
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (!byte)
			return (NULL);
		buffer[byte] = '\0';
		stacked = ft_strjoin(stacked, buffer);
	}
	line_len = ft_line_len(buffer);
	leftover = ft_substr(buffer, line_len, (byte - line_len));
	return (ft_substr(stacked, 0, ft_line_len(stacked)));
}
