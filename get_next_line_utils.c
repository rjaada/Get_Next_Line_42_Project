#include "get_next_line.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif

char get_next_char(int fd, char *buffer, int *buffer_index, int *buffer_size) {
    if (*buffer_index >= *buffer_size) {
        *buffer_size = read(fd, buffer, BUFFER_SIZE);
        *buffer_index = 0;
        if (*buffer_size <= 0) {
            return '\0'; // End of file or error
        }
    }
    return buffer[(*buffer_index)++];
}

char *construct_line(char *line, char c, int *line_index) {
    if (*line_index % BUFFER_SIZE == 0) {
        char *new_line = realloc(line, (*line_index) + BUFFER_SIZE + 1); // +1 for '\0'
        if (new_line == NULL) {
            free(line);
            return NULL;
        }
        line = new_line;
    }
    line[(*line_index)++] = c;
    if (c == '\n') {
        line[*line_index] = '\0'; // Null-terminate the line
    }
    return line;
}
