#ifndef MAP_H
# define MAP_H

# include <stdio.h>
# include <unistd.h>

# define SUCCESS 0
# define FAILURE 1

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53
# define X_EVENT_KEY_PRESS 2
// # define X_EVENT_KEY_RELEASE 3

typedef struct s_check{
	char	**map;
	int		width;
	int		height;
	int		num_c;
	int		num_p;
	int		num_e;
	int		status;//error메세지 뽑아줌
}	t_check;

typedef struct s_ptr{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_ptr;

typedef struct s_info{
	void	*img;
	int		state_x;
	int		state_y;
	int		flag;// 조건이 맞는지 C다먹었는지 ,E이 활성비활성
	int		width;
	int		height;
}	t_info;

typedef struct s_img{
	t_info	*img_ptr_0;
	t_info	*img_ptr_1;
	t_info	*img_ptr_P;
	t_info	*img_ptr_C;
	t_info	*img_ptr_E;
}	t_img;

typedef struct s_param{
	int	x;
	int	y;
	int	moves;
}	t_param;

int		print_error(char *str);
int		first_check(char *line, t_check *check);
int		mid_check(char *line, t_check *check);
int		final_check(char *line, t_check *check);
int		object_check(t_check *check);
int		count_hight(char *file, t_check *check);
int		check_them_all(char *file, t_check *check);
char	**ft_mapping(char *file, t_check *check);
void	check_init(t_check *check);
void	image_init(t_img *img, t_ptr *ptr);
void	ptr_init(t_ptr *ptr, t_check *check);

#endif