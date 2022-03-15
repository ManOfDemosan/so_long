/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:28:11 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/03/15 17:27:27 by jaehwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

#define SUCCESS 0
#define FAILURE 1

typedef struct s_check{
	int	width;
	int	hight;
	int	num_c;
	int	num_p;
	int	num_e;
}	t_check;

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
			return (print_error("ERROR: Wrong map structure!"));
		i++;
	}
	if (i == 0)
		return (print_error("ERROR: Wrong map structure!"));
	check->width = i;
	return (SUCCESS);
}

int	mid_check(char *line, t_check *check)
{
	int	i;

	i = 0;
	while (line[i] != '\n')
	{
		if (i == 0 && line[i] != '1')
			return (print_error("ERROR: Wrong map structure!"));
		if (line[i] == 'C')
			check->num_c++;
		else if (line[i] == 'P')
			check->num_p++;
		else if (line[i] == 'E')
			check->num_e++;
		else if (i != 0 && (line[i] == '0' || line[i] == '1'))
			return (print_error("ERROR: Wrong map structure!"));
		i++;
	}
	if (line [i - 1] != '1' || i != check->width)
		return (print_error("ERROR: Wrong map structure!"));
	return (SUCCESS);
}

int	final_check(char *line, t_check *check)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1')
			return (print_error("ERROR: Wrong map structure!"));
		i++;
	}
	if (i != check->width)
		return (print_error("ERROR: Wrong map structure!"));
	return (SUCCESS);
}

int	object_check(t_check *check)
{
	if (check->num_c < 1 || check->num_p > 1 || check->num_e > 1)
		return (print_error("ERROR: Object Is Not Valid!\n"));
	return (SUCCESS);
}
