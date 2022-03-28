/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:28:11 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/03/28 16:37:13 by jaehwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_error(char *str)
{
	printf("%s", str);
	exit(0);
}

int	first_check(char *line, t_check *check)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] != '1')
			print_error("1 ERROR: Wrong map structure!\n");
		i++;
	}
	if (i == 0)
		print_error("2 ERROR: Wrong map structure!\n");
	check->width = i;
	return (0);
}

int	mid_check(char *line, t_check *check)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (i == 0 && line[i] != '1')
			print_error("3 ERROR: Wrong map structure!\n");
		if (line[i] == 'E')
			check->num_e++;
		else if (line[i] == 'C')
			check->num_c++;
		else if (line[i] == 'P')
			check->num_p++;
		else if (i != 0 && !(line[i] == '0' || \
				 line[i] == '1' || line[i] == '\n'))
			print_error("4 ERROR: Wrong map structure!\n");
		i++;
	}
	if (line [i - 2] != '1' || i - 1 != check->width)
		print_error("5 ERROR: Wrong map structure!\n");
	return (0);
}

int	final_check(char *line, t_check *check)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1')
			print_error("6 ERROR: Wrong map structure!\n");
		i++;
	}
	if (i != check->width)
		print_error("7 ERROR: Wrong map structure!\n");
	return (0);
}

int	object_check(t_check *check)
{
	if (check->num_c < 1 || check->num_p != 1 || check->num_e != 1)
		print_error("8 ERROR: TARGET IS MISSING!\n");
	return (0);
}
