/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:10:39 by zibnoukh          #+#    #+#             */
/*   Updated: 2023/12/19 16:39:45 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, char c)
{
	if (s)
	{
		while (*s)
		{
			if (*s == c)
				return (s);
			s++;
		}
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}

char	*ft_get_the_line(char *s1)
{
	char	*str;
	int		i;

	if (!s1[0])
		return (NULL);
	str = malloc(ft_strlen(s1) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] && s1[i] != '\n')
	{
		str[i] = s1[i];
		i++;
	}
	if (s1[i] == '\n')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_s1(char *s1)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] && s1[i] != '\n')
		i++;
	if (!s1[i])
	{
		free(s1);
		return (NULL);
	}
	str = malloc(ft_strlen(s1) - i + 1);
	i += 1;
	if (!str)
		return (NULL);
	while (s1[i])
		str[j++] = s1[i++];
	str[j] = '\0';
	free(s1);
	return (str);
}
