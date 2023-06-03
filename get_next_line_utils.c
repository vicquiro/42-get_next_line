/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquiroga <vquiroga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 14:45:28 by vquiroga          #+#    #+#             */
/*   Updated: 2023/06/03 14:55:32 by vquiroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t len)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (len != 0 && i < len)
	{
		str[i] = '\0';
		i++;
	}
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

char	*ft_join_and_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
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
