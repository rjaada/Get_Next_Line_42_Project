/* Copyright 2024 Rachid Jaada \n* File name: get_next_line.c \n* Description: Read next line from a file descriptor \n*_
[include \"get_next_line.h\"]

# Helper function to read all lines from a file descriptor
char *read_all(int fd, char *text)
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
			free(text);
			return (NULL);
		}
		line[i] = '\0';
		text = ft_strjoin(text, line);
		if (!text)
		{
			return (NULL);
		}
	}
	free(line);
	return (text);
}

# Helper function to get the next line from the text
char
/*new_txt(char *text)
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
	newtxt = (char *)malloc(ft_strlen(text) - k);
	if (!newtxt)
		return (0);
	while (text[++k])
		newtxt[i++] = text[k];
	newtxt[i] = '\0';
	free(text);
	return (newtxt);
}
# Function to get the next line from a file descriptor
char *get_next_line(int fd)
{
	static char	*text = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	text = read_all(fd, text);
	if (!text)
		return (NULL);
	line = fg_t_line(text);
	text = new_txt(text);
	return (line);
}
int main(void)
{
  int fd;
  char *line;

  fd = open("test_file.txt", O-RDONLY);
  if (fd == -1) {
    perror("Error opening file");
    return 1;
  }
  // Test 1: Read one complete line
  line = get_next_line(fd);
  printf("Test 1: %s\n", line);
  free(line);
  // Test 2: Read one line with a newline character
  line = get_next_line(fd);
  printf("Test 2: %s\n", line);
  free(line);
  // Test 3: Read one line with special characters
  line = get_next_line(fd);
  printf(
    Test 3: %s\n", line);
  free(line);
  // Test 4: Read one line that surpasses the buffer size
  line = get_next_line(fd);
  printf("Test 4: %s\n", line);
  free(line);
  close(fd);
  return 0;
}