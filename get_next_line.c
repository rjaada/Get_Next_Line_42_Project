/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 02:16:39 by rjaada            #+#    #+#             */
/*   Updated: 2024/01/24 03:18:47 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

char	*get_next_line(int fd)
{
	char		*line;
	int			line_index;
	static char	buffer[BUFFER_SIZE];
	static int	buffer_index = 0, buffer_size = 0;
	char		c;

	line = NULL;
	line_index = 0;
	while (1)
	{
		c = get_next_char(fd, buffer, &buffer_index, &buffer_size);
		if (c == '\0')
			break ;
		line = construct_line(line, c, &line_index);
		if (line == NULL || c == '\n')
			break ;
	}
	if (buffer_size == 0 && (line == NULL || line_index == 0))
	{
		free(line);
		return (NULL);
	}
	return (line);
}

/*int	main(void)
{
    int fd = open("test_file.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    char *line;

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

    return 0;
}*/