#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include "mlx.h"
# include <fcntl.h>
# include "get_next_line.h"
# include <stdlib.h>

# define SUCCESS 0
# define FAILURE 1

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53
# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17
# define TILE_SIZE 64

typedef struct s_check{
	char	**map;
	int		width;
	int		height;
	int		num_c;
	int		num_p;
	int		num_e;
}	t_check;

typedef struct s_image
{
	void		*image_pointer;
	int			height;
	int			width;
}				t_image;

typedef struct s_tiles
{
	t_image		wall;
	t_image		space;
	t_image		player;
	t_image		collectible;
	t_image		exit;
}				t_tiles;

typedef struct s_player
{
	int			current_x;
	int			current_y;
	int			moves;
	int			did_collect;
}				t_player;

typedef struct s_exit
{
	int			x;
	int			y;
	int			is_opened;
}				t_exit;

typedef struct s_collectible
{
	int			x;
	int			y;
	int			is_collected;
}				t_collectible;

typedef struct s_game
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			**map;
	int				map_height;
	int				map_width;
	int				number_of_collectibles;
	t_tiles			tiles;
	t_player		player;
	t_exit			exit;
	t_collectible	*collectibles;
}					t_game;

void		print_error(char *str);
int			first_check(char *line, t_check *check);
int			mid_check(char *line, t_check *check);
int			final_check(char *line, t_check *check);
int			object_check(t_check *check);
//mapcheck

void		check_and_save_map(char *file, t_check *check);
void		print_map(t_game *game, t_check *check);
//map save
void		init_features(t_game *game);
void		check_init(t_check *check);
void		image_init(t_game *game);
//init game
void		ptr_init(t_game *game);
int			key_press(int key, t_game *game);
void		draw_map(t_game *game, t_check *check);
//print game
#endif