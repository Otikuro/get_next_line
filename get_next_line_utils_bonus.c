/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juamanri <juamanri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:18:13 by juamanri          #+#    #+#             */
/*   Updated: 2025/05/23 12:18:27 by juamanri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

size_t	ft_strlen(const char *string)
{
	size_t	i;

	if (string == NULL)
		return (0);
	i = 0;
	while (string[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*copy;

	if (s == NULL)
		return (NULL);
	i = 0;
	copy = (char *)malloc(ft_strlen(s) + 1);
	if (copy == NULL)
		return (NULL);
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (size < 1)
		return (src_len);
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	unsigned int		objective_len;
	char				*str;

	if (s == NULL)
		return (NULL);
	objective_len = ft_strlen(s);
	if (start > objective_len)
		return (ft_strdup(""));
	if (len > (objective_len - start))
		len = objective_len - start;
	if (len < 1)
	{
		str = (char *)malloc(sizeof(char) * 1);
		if (str == NULL)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, &s[start], len + 1);
	return (str);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	int		i;
	int		s1_len;
	int		s2_len;
	char	*str;

	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc((s1_len + s2_len) + 1);
	if (str == NULL)
		return (free(s1), NULL);
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
	return (free(s1), str);
}