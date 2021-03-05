/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <hballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 09:52:03 by hballaba          #+#    #+#             */
/*   Updated: 2020/06/10 11:04:03 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_copy(char *buf)
{
	size_t i;

	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	buf[i] = '\0';
	return (buf);
}

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*res;

	size = 0;
	while (s[size])
		size++;
	res = (char*)malloc(sizeof(char) * size + 1);
	if (res == NULL)
		return (NULL);
	size = 0;
	while (s[size])
	{
		res[size] = s[size];
		size++;
	}
	res[size] = '\0';
	return (res);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	size_t	lens1;
	size_t	lens2;

	lens1 = ft_strlen((char*)s1);
	lens2 = ft_strlen((char*)s2);
	str = (char*)malloc(lens1 + lens2 + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, lens1 + 1);
	ft_strlcat(str, s2, lens2 + lens1 + 1);
	free(s1);
	s1 = NULL;
	return (str);
}

int		workgnl(int fd, char **line, int size, int reader)
{
	static char	*repa[1];
	char		buf[size + 1];

	*line = ft_strdup("");
	if (!repa[fd])
	{
		if ((reader = read(fd, &buf, BUFFER_SIZE)) < 0)
			return (-1);
	}
	else
		ft_memcpy(buf, repa[fd]);
	buf[reader] = '\0';
	while ((!(repa[fd] = ft_strchr(buf, '\n')) && reader == size))
	{
		*line = ft_strjoin(*line, ft_copy(buf));
		reader = read(fd, &buf, size);
		buf[reader] = '\0';
	}
	if (reader > 0)
		*line = ft_strjoin(*line, ft_copy(buf));
	if ((!repa[fd]) && reader < size)
		return (2);
	repa[fd] = ft_strdup(repa[fd]);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	int		i;
	int		reader;

	reader = BUFFER_SIZE;
	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	i = workgnl(fd, line, BUFFER_SIZE, reader);
	if (i == 2)
		return (0);
	return (i);
}
