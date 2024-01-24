/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 02:42:29 by rjaada            #+#    #+#             */
/*   Updated: 2024/01/24 05:33:00 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr(char *s1, char c)
{
	int	i;

	i = 0;
	if (!s1)
		return (0);
	while (s1[i])
	{
		if (s1[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	int		p_len;
	int		i;
	int		j;

	j = 0;
	i = -1;
	if (!s2)
		return (NULL);
	if (!s1)
	{
		s1 = (char *)malloc (1 * sizeof(char));
		s1[0] = 0;
	}
	p_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	p = (char *)malloc(sizeof(char) * p_len);
	if (!p)
		return (NULL);
	while (s1[++i])
		p[i] = s1[i];
	while (s2[j])
		p[i++] = s2[j++];
	p[i] = '\0';
	free(s1);
	return (p);
}

char	*get_line(char *text)
{
	char	*line;
	size_t	len;
	size_t	j;

	len = 0;
	j = 0;
	if (text[0] == '\0')
		return (NULL);
	while (text[len] != '\n' && text[len] != '\0')
		len++;
	if (text[len] == '\n')
		len++;
	line = (char *)malloc(len + 1);
	if (!line)
		return (0);
	while (j < len)
	{
		line[j] = text[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}
