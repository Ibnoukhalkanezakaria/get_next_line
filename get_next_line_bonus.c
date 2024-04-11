/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:10:39 by zibnoukh          #+#    #+#             */
/*   Updated: 2023/12/19 20:04:24 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_read(int fd, char *s1)
{
	char	*buffer;
	ssize_t	bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	bytes = 1;
	while (bytes > 0 && !ft_strchr(s1, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		s1 = ft_strjoin(s1, buffer);
	}
	free(buffer);
	return (s1);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*s1[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s1[fd] = ft_read(fd, s1[fd]);
	if (!s1[fd])
		return (NULL);
	line = ft_get_the_line(s1[fd]);
	s1[fd] = ft_s1(s1[fd]);
	return (line);
}
