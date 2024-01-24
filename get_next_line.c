/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 02:16:39 by rjaada            #+#    #+#             */
/*   Updated: 2024/01/24 05:33:35 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

char	*read_all(int fd, char *text)
{
	ssize_t	i;
	char	*line;

	line = (char *)malloc(BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	i = 1;
	while (!(ft_strchr(text, '\n')) && i != 0)
	{
		i = read(fd, line, BUFFER_SIZE);
		if (i == -1)
		{
			free(line);
			return (NULL);
		}
		line[i] = '\0';
		text = ft_strjoin(text, line);
	}
	free(line);
	return (text);
}

char	*new_txt(char *text)
{
	char	*newtxt;
	size_t	k;
	size_t	i;

	k = 0;
	i = 0;
	while (text[k] != '\n' && text[k] != '\0')
		k++;
	if (!text[k])
	{
		free(text);
		return (NULL);
	}
	newtxt = (char *)malloc(ft_strlen(text) - k + 1);
	if (!newtxt)
		return (0);
	while (text[k++])
		newtxt[i++] = text[k];
	newtxt[i] = '\0';
	free(text);
	return (newtxt);
}

char	*get_next_line(int fd)
{
	static char	*text;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	text = read_all(fd, text);
	if (!text)
		return (NULL);
	line = get_line(text);
	text = new_txt(text);
	return (line);
}

/*int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test_file.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Erreur lors de l'ouverture du fichier");
		return (1);
	}
	// Test 1: Lire une ligne complète
	line = get_next_line(fd);
	printf("Test 1: %s\n", line);
	free(line);
	// Test 2: Lire une ligne vide
	line = get_next_line(fd);
	printf("Test 2: %s\n", line);
	free(line);
	// Test 3: Lire une ligne avec des caractères spéciaux
	line = get_next_line(fd);
	printf("Test 3: %s\n", line);
	free(line);
	// Test 4: Lire une ligne qui dépasse la taille du tampon
	line = get_next_line(fd);
	printf("Test 4: %s\n", line);
	free(line);
	close(fd);
	return (0);
}*/
