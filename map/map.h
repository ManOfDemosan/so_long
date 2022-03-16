#ifndef MAP_H
# define MAP_H

#include <stdio.h>
#include <unistd.h>

#define SUCCESS 0
#define FAILURE 1

typedef struct s_check{
	int	width;
	int	height;
	int	num_c;
	int	num_p;
	int	num_e;
	int	status;
}	t_check;

int	print_error(char *str);
int	first_check(char *line, t_check *check);
int	mid_check(char *line, t_check *check);
int	final_check(char *line, t_check *check);
int	object_check(t_check *check);
int	count_hight(char *file, t_check *check);
int	check_them_all(char *file, t_check *check);
#endif