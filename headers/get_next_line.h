#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#define BUFFER_SIZE 32
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
void	ft_bzero(void *s, size_t len);
size_t	ft_strlen(const char *s);

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_join_and_free(char *buffer, char *buf);
void	*ft_calloc(size_t count, size_t size);
int     ft_containsNewLine(const char *buff);
char	*ft_next(char *buffer);
char	*ft_line(char *buffer);
char	*read_file(int fd, char *res);
char	*get_next_line(int fd);

#endif
