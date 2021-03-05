/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <hballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 09:51:48 by hballaba          #+#    #+#             */
/*   Updated: 2020/06/10 10:23:51 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_strchr(const char *str, int ch)
{
	char *dest;

	dest = (char*)str;
	while (*dest && *dest != ch)
		dest++;
	if (*dest == ch)
		return (dest + 1);
	else
		return (NULL);
}

char	*ft_memcpy(char *dest, char *src)
{
	char	*buf;
	char	*dst;
	size_t	i;

	if (!src && !dest)
		return (dest);
	dst = (char*)dest;
	buf = (char*)src;
	i = 0;
	while (src[i])
	{
		dst[i] = buf[i];
		i++;
	}
	dst[i] = '\0';
	free(src);
	src = NULL;
	dest = dst;
	return (dest);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t lendst;
	size_t lensrc;

	lendst = ft_strlen(dst);
	lensrc = ft_strlen((char*)src);
	i = lendst + lensrc;
	if (size <= lendst)
		return (lensrc + size);
	while (*src && size > lendst + 1)
	{
		dst[lendst] = *src;
		src++;
		lendst++;
	}
	dst[lendst] = '\0';
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t count;
	size_t i;

	count = 0;
	if (!dst)
		return (0);
	if (!size)
		return (ft_strlen((char*)src));
	while (src[count] != '\0')
		count++;
	i = 0;
	while (src[i] != '\0' && size > 1)
	{
		dst[i] = src[i];
		i++;
		size--;
	}
	dst[i] = '\0';
	return (count);
}
