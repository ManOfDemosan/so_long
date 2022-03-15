/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:28:11 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/03/15 18:43:35 by jaehwkim         ###   ########.fr       */
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

int	first_check(char *line, t_check check)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] != '1')
			return (print_error("1 ERROR: Wrong map structure!\n"));
		i++;
	}
	if (i == 0)
		return (print_error("2 ERROR: Wrong map structure!\n"));
	check.width = i;
	printf("first line 성공\n");
	return (SUCCESS);
}

int	mid_check(char *line, t_check check)
{
	int	i;

	i = 0;
	while (line[i] != '\n')
	{
		if (i == 0 && line[i] != '1')
			return (print_error("3 ERROR: Wrong map structure!\n"));
		if (line[i] == 'C')
		{
			check.num_c++;
			printf("C카운트++\n");
		}
		else if (line[i] == 'P')
		{
			check.num_p++;
			printf("P카운트++\n");
		}
		else if (line[i] == 'E')
		{
			check.num_e++;
			printf("E카운트++\n");
		}
		else if (i != 0 && !(line[i] == '0' || line[i] == '1'))
			return (print_error("4 ERROR: Wrong map structure!\n"));
		i++;
	}
	if (line [i - 1] != '1' || i != check.width)
		return (print_error("5 ERROR: Wrong map structure!\n"));

	printf("mid line 성공\n");
	return (SUCCESS);
}

int	final_check(char *line, t_check check)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1')
			return (print_error("6 ERROR: Wrong map structure!\n"));
		i++;
	}
	if (i != check.width)
		return (print_error("7 ERROR: Wrong map structure!\n"));
	printf("final line 성공!\n");
	return (SUCCESS);
}
int	object_check(t_check check)
{
	if (check.num_c < 1)
		return (print_error("8 ERROR: Collactavle Is Not Valid!\n"));
	else if (check.num_p != 1)
		return (print_error("9 ERROR: Player Is Not Valid!\n"));
	else if (check.num_e != 1)
		return (print_error("10 ERROR: Exit Is Not Valid!\n"));
	printf("Object 성공!\n");
	return (SUCCESS);
}

int	main(void)
{
	t_check	check;
	check.width = 5;
	check.hight = 0;
	check.num_p = 1;
	check.num_c = 1;
	check.num_e = 1;
	char arr [6][7] = {
		{'1', '1', '1', '1', '1', '\n'},
		{'1', '0', '0', '0', '1', '\n'},
		{'1', '0', '0', '0', '1', '\n'},
		{'1', '0', '0', '0', '1', '\n'},
		{'1', '1', '1', '1', '1', '\0'},
		NULL
	};

	first_check(arr[0], check);
	printf("=======================\n");
	mid_check(arr[1], check);
	printf("=======================\n");
	mid_check(arr[2], check);
	printf("=======================\n");
	mid_check(arr[3], check);
	printf("=======================\n");
	final_check(arr[4],check);
	printf("=======================\n");
	object_check(check);
}