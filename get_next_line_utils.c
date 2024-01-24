/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 02:42:29 by rjaada            #+#    #+#             */
/*   Updated: 2024/01/24 02:50:58 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

char	get_next_char(int fd, char *buffer, int *buffer_index, int *buffer_size)
{
	if (*buffer_index >= *buffer_size)
	{
		*buffer_size = read(fd, buffer, BUFFER_SIZE);
		*buffer_index = 0;
		if (*buffer_size <= 0)
		{
			return ('\0');
		}
	}
	return (buffer[(*buffer_index)++]);
}

char	*construct_line(char *line, char c, int *line_index)
{
	char	*new_line;

	if (*line_index % BUFFER_SIZE == 0)
	{
		new_line = realloc(line, (*line_index) + BUFFER_SIZE + 1);
		if (new_line == NULL)
		{
			free(line);
			return (NULL);
		}
		line = new_line;
	}
	line[(*line_index)++] = c;
	if (c == '\n')
	{
		line[*line_index] = '\0';
	}
	return (line);
}
