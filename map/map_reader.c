/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:29:00 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/03/23 18:36:38 by jaehwkim         ###   ########.fr       */
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

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (FAILURE);
	line = get_next_line(fd);
	if (line == NULL)
		return (0);
	first_check(line, check);
	while (line > 0)
	{
		free(line);
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line[check->width] != '\0')
			mid_check(line, check);
		else if (line[check->width] == '\0')
			final_check(line, check);
	}
	object_check(check);
	free(line);
	close(fd);
	return (check->status);
}

char	**ft_mapping(char *file, t_check *check)
{
	char	**map;
	int		fd;
	int		i;

	map = malloc(sizeof(char *) * (check->height + 1));
	map[check->height] = NULL;
	fd = open(file, O_RDONLY);
	i = 0;
	while (i < check->height)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	check->map = map;
	return (map);
}

// int	main(void)
// {

// 	int		i = 0;

// 	t_check	check;
// 	check.status = 0;
// 	check.width = 0;
// 	check.height = 0;
// 	check.num_p = 0;
// 	check.num_c = 0;
// 	check.num_e = 0;

// 	count_hight("mape.ber", &check);
// 	check_them_all("mape.ber", &check);
// 	// if (check.status == SUCCESS)
// 	// 	printf("SUCCESS!\n");
// 	// if (check.status == FAILURE)
// 	// 	printf("FAILURE!\n");
// 	ft_mapping("mape.ber", &check);
// 	while (i < 5)
// 	{
// 		printf("%s", check.map[i]);
// 		i++;
// 	}
// }
