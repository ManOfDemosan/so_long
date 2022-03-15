/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:10:38 by jaehwkim          #+#    #+#             */
/*   Updated: 2021/12/17 18:09:25 by jaehwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == 0)
		return (0);
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	if (str == 0)
		return (0);
	if ((unsigned char)c == '\0')
		return ((char *)str);
	while (*str != '\0')
	{
		if (*str == (unsigned char)c)
			return ((char *)str);
		str++;
	}
	return (0);
}

char	*ft_strjoin(char *static_buffer, char *buf)
{
	char	*str;
	int		size_static_buffer;
	int		size_buf;
	int		i;

	size_static_buffer = ft_strlen(static_buffer);
	size_buf = ft_strlen(buf);
	if (static_buffer == 0)
	{
		static_buffer = (char *)malloc(1 * sizeof(char));
		static_buffer[0] = '\0';
	}
	if (static_buffer == 0 && buf == 0)
		return (0);
	str = malloc(sizeof(char) * (size_static_buffer + size_buf + 1));
	i = -1;
	while (static_buffer[++i] != '\0')
		str[i] = static_buffer[i];
	while (*buf != '\0')
		str[i++] = *buf++;
	str[size_static_buffer + size_buf] = '\0';
	free(static_buffer);
	return (str);
}
