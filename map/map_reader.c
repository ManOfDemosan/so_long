/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:29:00 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/03/15 21:01:08 by jaehwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <fcntl.h>
#include "../get_next_line/get_next_line.h"

int	count_hight(char *file, t_check *check)
{
	int		height;
	int		readcount;
	int		fd;
	char	c;


	fd = open(file, O_RDONLY);
	if (fd == NULL)
		return (-1);
	height = 1;
	while (height != NULL)
	{
		readcount = read(fd, &c, 1);
		if (readcount == 0)
			break ;
		if (readcount < 0)
			return (-1);
		if (c == '\n')
			height++;
	}
	close(fd);
	check->height = height;
	return (height);
}

int	check_them_all(char *file, t_check *check)
{
	int		fd;
	char	*line;
	int		flag;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
		return (NULL);
	flag = first_check(line, check);
	while (line != NULL)
	{
		free(line);
		line = NULL;
		line = get_next_line(fd);
		if (line[check->width] != '\0')
			mid_check(line, check);
		else if (line[check->width] == '\0')
			final_check(line, check);
	}
	free(line);
	line = NULL;
	close(fd);
	return (SUCCESS);
}
