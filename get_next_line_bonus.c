/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juamanri <juamanri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:02:16 by juamanri          #+#    #+#             */
/*   Updated: 2025/05/27 12:45:41 by juamanri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line_bonus.h"

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

int	ft_initialize(char **leftover, char **stack, char **buff, int fd)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (*leftover == NULL)
		*leftover = ft_strdup("");
	if (*leftover == NULL)
		return (0);
	*stack = ft_strdup(*leftover);
	if (*stack == NULL)
		return (free(*leftover), *leftover = NULL, 0);
	*buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (*buff == NULL)
		return (free(*leftover), free(*stack),
			*leftover = NULL, *stack = NULL, 0);
	(*buff)[0] = '\0';
	if (ft_get_newline_index(*stack) != -1)
		ft_strlcpy(*buff, *stack, BUFFER_SIZE);
	return (free(*leftover), *leftover = NULL, 1);
}

char	*get_next_line(int fd)
{
	static char	*leftover[1024];
	char		*stack;
	char		*buff;
	char		*line;
	int			byte;

	byte = 0;
	if (!ft_initialize(&leftover[fd], &stack, &buff, fd))
		return (NULL);
	while (ft_get_newline_index(stack) == -1)
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte == 0 && stack[0] != '\0')
		{
			leftover[fd] = ft_strdup("");
			return (free(buff), buff = NULL, stack);
		}
		else if (byte == 0)
			return (free(stack), free(buff), stack = NULL, buff = NULL, NULL);
		buff[byte] = '\0';
		stack = ft_strjoin(stack, buff);
	}
	leftover[fd] = ft_strdup(stack + ft_get_newline_index(stack) + 1);
	line = ft_substr(stack, 0, ft_get_newline_index(stack) + 1);
	return (free(stack), free(buff), stack = NULL, buff = NULL, line);
}
