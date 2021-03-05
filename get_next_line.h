/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <hballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 09:56:11 by hballaba          #+#    #+#             */
/*   Updated: 2020/06/10 10:23:54 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int		ft_strlen(char *str);
char	*ft_strchr(const char *str, int ch);
char	*ft_memcpy(char *dest, char *src);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_copy(char *buf);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char const *s2);
int		workgnl(int fd, char **line, int size, int reader);
int		get_next_line(int fd, char **line);

#endif
