#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

char *get_next_line(int fd)
{    
    static char buffer[BUFFER_SIZE];
    static int buffer_index = 0;
    static int buffer_size = 0;

    char *line = NULL;
    int line_index = 0;
    char c;

    while (1)
    {
        // Check if buffer is empty, read more data if needed
        if (buffer_index >= buffer_size)
        {
            buffer_size = read(fd, buffer, BUFFER_SIZE);
            buffer_index = 0;

            if (buffer_size <= 0)
                break;
        }

        c = buffer[buffer_index++];
        
        // Check for end of line
        if (c == '\n')
            break;

        // Reallocate memory if line exceeds BUFFER_SIZE
        if (line_index % BUFFER_SIZE == 0)
        {
            char *new_line = realloc(line, (line_index + BUFFER_SIZE) * sizeof(char));
            if (new_line == NULL)
            {
                free(line);
                return NULL;
            }
            line = new_line;
        }

        line[line_index++] = c;
    }

    // Handle end-of-file (EOF)
    if (buffer_size == 0 && line_index == 0)
    {
        free(line);
        return NULL;
    }

    // Null-terminate the line
    line[line_index] = '\0';

    return line;
}

int main()
{
    int fd = open("test_file.txt", O_RDONLY); // Remplacez "test.txt" par le chemin vers votre fichier de test

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
}