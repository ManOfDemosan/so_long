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
}	t_check;

#endif