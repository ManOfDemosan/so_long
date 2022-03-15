/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:29:00 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/03/15 22:37:03 by jaehwkim         ###   ########.fr       */
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
	if (fd == 0)
		return (-1);
	height = 1;
	while (height != 0)
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
	if (fd < 0)
		return (FAILURE);
	line = get_next_line(fd);
	if (line == NULL)
		return (0);
	flag = first_check(line, check);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line[check->width - 1] != '\0')
			mid_check(line, check);
		else if (line[check->width - 1] == '\0')
			final_check(line, check);
	}
	free(line);
	close(fd);
	return (SUCCESS);
}

int	main(void)
{
	int status;
	t_check	check;
	check.width = 0;
	check.height = 0;
	check.num_p = 0;
	check.num_c = 0;
	check.num_e = 0;

	status = check_them_all("mape.ber", &check);
	if (status == SUCCESS)
		printf("SUCCESS!\n");
	if (status == FAILURE)
		printf("FAILURE!\n");
}