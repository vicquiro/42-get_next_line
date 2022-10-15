/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquiroga <vquiroga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:44:05 by vquiroga          #+#    #+#             */
/*   Updated: 2022/10/15 16:50:16 by vquiroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>

void	ft_read_line(int fd, char **keep, char **tmp)
{
	char	*buf;
	int		r;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return ;
	r = 1;
	while (r > 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
		{
			ft_free_strs(&buf, keep, tmp);
			return ;
		}
		buf[r] = '\0';
		*tmp = ft_strdup(*keep);
		ft_free_strs(keep, 0, 0);
		*keep = join_strs(*tmp, buf);
		ft_free_strs(tmp, 0, 0);
		if (contains_newline(*keep))
			break ;


char	*get_next_line(int fd)
{
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	(void)argc;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	line = "";
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	fd = close(fd);
	return (0);
}

// void function(void)
// {
// 	static char	*x; //Valor de una variable estatica por defecto es 0

// 	printf("x = %s\n", x);
// 	x = x + 1;
// }
// int main(void)
// {
// 	int i;

// 	i = 0;
// 	while (i <= 10)
// 	{
// 		function();
// 		i++;
// 	}
// 	return (0);
// }
