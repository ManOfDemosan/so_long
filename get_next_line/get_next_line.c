/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:05:14 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/03/15 17:53:29 by jaehwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*how_to_read(int fd, char *static_buffer)
{
	char	*buf;
	int		button;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == 0)
		return (0);
	button = 1;
	while (button != 0 && !ft_strchr(static_buffer, '\n'))
	{
		button = read(fd, buf, BUFFER_SIZE);
		if (button == -1)
		{
			free(buf);
			return (0);
		}
		buf[button] = 0;
		static_buffer = ft_strjoin(static_buffer, buf);
	}
	free(buf);
	return (static_buffer);
}

char	*put_line(char *static_buffer)
{
	char	*str;
	int		i;

	i = 0;
	if (static_buffer[i] == 0)
		return (0);
	while (static_buffer[i] != 0 && static_buffer[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (str == 0)
		return (0);
	i = 0;
	while (static_buffer[i] != 0 && static_buffer[i] != '\n')
	{
		str[i] = static_buffer[i];
		i++;
	}
	if (static_buffer[i] == '\n')
	{
		str[i] = static_buffer[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*new_buffer(char *static_buffer)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (static_buffer[i] != 0 && static_buffer[i] != '\n')
		i++;
	if (static_buffer[i] == 0)
	{
		free(static_buffer);
		return (0);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(static_buffer) - i + 1));
	if (str == 0)
		return (0);
	i++;
	j = 0;
	while (static_buffer[i] != 0)
		str[j++] = static_buffer[i++];
	str[j] = '\0';
	free(static_buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char			*static_buffer;
	char				*line;

	if (fd < 0 || fd > ARRAY_MAX || BUFFER_SIZE < 1)
		return (0);
	static_buffer = how_to_read(fd, static_buffer);
	if (static_buffer == 0)
		return (0);
	line = put_line(static_buffer);
	static_buffer = new_buffer(static_buffer);
	return (line);
}
