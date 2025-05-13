/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juamanri <juamanri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:26:59 by juamanri          #+#    #+#             */
/*   Updated: 2025/05/13 12:58:40 by juamanri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_
#include <unistd.h>
#include <stdlib.h>
#define BUFFER_SIZE 50
char	*get_next_line(int fd);
#endif