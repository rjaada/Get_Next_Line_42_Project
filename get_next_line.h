#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>


char get_next_char(int fd, char *buffer, int *buffer_index, int *buffer_size);
char *construct_line(char *line, char c, int *line_index);
char *get_next_line(int fd);

#endif
