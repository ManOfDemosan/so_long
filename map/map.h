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
 
typedef struct s_ptr{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_ptr;

typedef struct s_info{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_info;

typedef struct s_img{
	t_info	*img_ptr0;
	t_info	*img_ptr1;
	t_info	*img_ptr_P;
	t_info	*img_ptr_C;
	t_info	*img_ptr_E;
}	t_img;



int	print_error(char *str);
int	first_check(char *line, t_check *check);
int	mid_check(char *line, t_check *check);
int	final_check(char *line, t_check *check);
int	object_check(t_check *check);
int	count_hight(char *file, t_check *check);
int	check_them_all(char *file, t_check *check);
char **ft_mapping(char *file, t_check *check);
#endif