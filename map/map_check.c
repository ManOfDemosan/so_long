/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:28:11 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/03/23 18:33:56 by jaehwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	print_error(char *str)
{
	printf("%s", str);
	return (FAILURE);
}

int	first_check(char *line, t_check *check)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] != '1')
			return (check->status = \
			print_error("1 ERROR: Wrong map structure!\n"));
		i++;
	}
	if (i == 0)
		return (check->status = print_error("2 ERROR: Wrong map structure!\n"));
	check->width = i;
	return (check->status);
}

int	mid_check(char *line, t_check *check)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (i == 0 && line[i] != '1')
			return (check->status = \
			print_error("3 ERROR: Wrong map structure!\n"));
		if (line[i] == 'E')
			check->num_e++;
		else if (line[i] == 'C')
			check->num_c++;
		else if (line[i] == 'P')
			check->num_p++;
		else if (i != 0 && !(line[i] == '0' || \
				 line[i] == '1' || line[i] == '\n'))
			return (check->status = \
			print_error("4 ERROR: Wrong map structure!\n"));
		i++;
	}
	if (line [i - 2] != '1' || i - 1 != check->width)
		return (check->status = print_error("5 ERROR: Wrong map structure!\n"));
	return (check->status);
}

int	final_check(char *line, t_check *check)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1')
			return (check->status = \
			print_error("6 ERROR: Wrong map structure!\n"));
		i++;
	}
	if (i != check->width)
		return (check->status = print_error("7 ERROR: Wrong map structure!\n"));
	return (check->status);
}

int	object_check(t_check *check)
{
	if (check->num_c < 1)
		return (check->status = \
		print_error("8 ERROR: Collactavle Is Not Valid!\n"));
	else if (check->num_p != 1)
		return (check->status = print_error("9 ERROR: Player Is Not Valid!\n"));
	else if (check->num_e != 1)
		return (check->status = print_error("10 ERROR: Exit Is Not Valid!\n"));
	return (check->status);
}

// int main(void)
// {
// 	char *line;
// 	int	fd;
// 	t_check	check;
// 	int	status;
// 	char **map;

// 	fd = open("map.ber", O_RDONLY);
// 	line = get_next_line(fd);
// 	if (line == NULL)
// 		exit(0);
// 	status = first_check(line, &check);
// 	if (status != SUCCESS)
// 		return (0);
// 	while (line != NULL)
// 	{
// 		free(line);
// 		line = NULL;
// 		line = get_next_line(fd);
// 		if (line[check.width] != '\0')
// 			mid_check(line, &check);
// 		else if (line[check.width] == '\0')
// 			final_check(line, &check);
// 	}
// 	free(line);
// 	line = NULL;
// 	close(fd);

// 	map = malloc(sizeof(char *) * (check.height + 1));
// 	int index = 0;
// 	fd = open("map.ber", O_RDONLY);
// 	while (index < check.height)
// 	{
// 		line = get_next_line(fd);
// 		map[index] = line;
// 		++index;
// 		free(line);
// 		line = NULL;
// 	}



// }