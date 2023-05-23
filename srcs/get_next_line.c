/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquiroga <vquiroga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:25:19 by vquiroga          #+#    #+#             */
/*   Updated: 2022/10/15 16:39:12 by vquiroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include <fcntl.h>

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
