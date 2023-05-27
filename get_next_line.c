#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

void	ft_bzero(void *s, size_t len)
{
	unsigned char	*str;
	size_t	i;

	str = (unsigned char *)s;
	i = 0;
	while (len != 0 && i < len)
	{
		str[i] = '\0';
		i++;
	}
}


void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_len;
	void	*dst;

	total_len = count * size;
	if (total_len && (total_len / size != count))
		return (0);
	dst = malloc(total_len);
	if (!dst)
		return (0);
	ft_bzero(dst, total_len);
	return (dst);
}




int ft_containsNewLine(const char *buff)
{
    int i;

    i = 0;
    while (buff[i] != '\0')
    {
        if (buff[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}




size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_out;
	size_t	i;
	size_t	j;
	char	*str_out;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	len_out = ft_strlen(s1) + ft_strlen(s2);
	str_out = malloc(sizeof(char) * (len_out + 1));
	if (!str_out)
		return (0);
	while (s1[i] != '\0' && j < len_out)
		str_out[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0' && j < len_out)
		str_out[j++] = s2[i++];
	str_out[j] = '\0';
	return (str_out);
}

// join and free
char	*ft_join_and_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

//TODO: Review this function

// delete line find
char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	// find len of first line
	while (buffer[i] && buffer[i] != '\n')
		i++;
	// if eol == \0 return NULL
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	// len of file - len of firstline + 1
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	// line == buffer
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

//TODO: Review this function

// take line for return
char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	// if no line return NULL
	if (!buffer[i])
		return (NULL);
	// go to the eol
	while (buffer[i] && buffer[i] != '\n')
		i++;
	// malloc to eol
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	// line = buffer
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	// if eol is \0 or \n, replace eol by \n
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

//
char	*read_file(int fd, char *res)
{
	char	*buffer;
	int		byte_read;

	// malloc if res dont exist
	if (!res)
		res = ft_calloc(1, 1);
	// malloc buffer
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		// while not eof read
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		// 0 to end for leak
		buffer[byte_read] = 0;
		// join and free
		res = ft_join_and_free(res, buffer);
		// TODO: quit if \n find
		if(ft_containsNewLine(buffer))
			break;

		// if (ft_strchr(buffer, '\n'))
		// 	break ;
	}
	free(buffer);
	return (res);
}


char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_next(buffer);
	return (line);
}

// int	main(int argc, char **argv)
// {
// 	int		fd;
// 	char	*line;

// 	(void)argc;

// 	fd = open(argv[1], O_RDONLY);
// 	if (fd == -1)
// 		return (-1);
// 	line = "";
// 	while (line != NULL)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 	}
// 	fd = close(fd);
// 	return (0);
// }
