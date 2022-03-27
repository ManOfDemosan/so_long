/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:11:22 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/03/27 19:12:47 by jaehwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line/get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include "mlx.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "./map/map.h"

void	check_init(t_check *check)
{
	check->width = 0;
	check->height = 0;
	check->num_p = 0;
	check->num_c = 0;
	check->num_e = 0;
}

void	init_player(t_game *game, int x, int y)
{
	game->player.current_x = x;
	game->player.current_y = y;
	game->player.moves = 0;
	game->player.did_collect = 0;
}

void	init_exit(t_game *game, int x, int y)
{
	game->exit.x = x;
	game->exit.y = y;
	game->exit.is_opened = 0;
}

void	init_collectibles(t_game *game, int x, int y)
{
	static int		i;
	t_collectible	collectible;

	collectible.x = x;
	collectible.y = y;
	collectible.is_collected = 0;
	game->collectibles[i] = collectible;
	i++;
}

void	init_features(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->collectibles = (t_collectible *)malloc(sizeof(t_collectible)
			* game->number_of_collectibles);
	if (game->collectibles == NULL)
		print_error("Failed to malloc collectible array");
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == 'P')
				init_player(game, j, i);
			else if (game->map[i][j] == 'C')
				init_collectibles(game, j, i);
			else if (game->map[i][j] == 'E')
				init_exit(game, j, i);
			j++;
		}
		i++;
	}
}

void	make_2d_map(t_check *check, t_game *game)
{
	char	**arr_map;

	arr_map = (char **)malloc(sizeof(char *) * (check->height + 1));
	if (arr_map == NULL)
		print_error("2d map malloc failed.");
	arr_map = check->map;
	game->map = arr_map;
	game->map_height = check->height;
	game->map_width = check->width;
	game->number_of_collectibles = check->num_c;
}

void	image_init(t_game *game)
{
	t_tiles	tiles;

	tiles.space.image_pointer = mlx_xpm_file_to_image(game->mlx_ptr, \
	"./xpm/0.64.xpm", &tiles.space.width, &tiles.space.height);
	tiles.wall.image_pointer = mlx_xpm_file_to_image(game->mlx_ptr, \
	"./xpm/1.64.xpm", &tiles.wall.width, &tiles.wall.height);
	tiles.player.image_pointer = mlx_xpm_file_to_image(game->mlx_ptr, \
	"./xpm/P64.xpm", &tiles.player.width, &tiles.player.height);
	tiles.collectible.image_pointer = mlx_xpm_file_to_image(game->mlx_ptr, \
	"./xpm/C64.xpm", &tiles.collectible.width, &tiles.collectible.height);
	tiles.exit.image_pointer = mlx_xpm_file_to_image(game->mlx_ptr, \
	 "./xpm/E64.xpm", &tiles.exit.width, &tiles.exit.height);
	 game->tiles = tiles;
}

void	ptr_init(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, \
		game->map_width * TILE_SIZE, game->map_height * TILE_SIZE, "choon!");
}

void	new_map(int x, int y, t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
				game->tiles.space.image_pointer, x * TILE_SIZE, y * TILE_SIZE);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->tiles.player.image_pointer, \
		game->player.current_x * TILE_SIZE, game->player.current_y * TILE_SIZE);
}

void	move_check_wall(int key, t_game *game)
{
	int	save_x;
	int	save_y;

	save_x = game->player.current_x;
	save_y = game->player.current_y;
	if (key != KEY_ESC)
	{
		if (key == KEY_W && game->map[game->player.current_y - 1] \
		[game->player.current_x] != '1')
			game->player.current_y--;
		else if (key == KEY_S && game->map[game->player.current_y + 1] \
		[game->player.current_x] != '1')
			game->player.current_y++;
		else if (key == KEY_D && game->map[game->player.current_y] \
		[game->player.current_x + 1] != '1')
			game->player.current_x++;
		else if (key == KEY_A && game->map[game->player.current_y] \
		[game->player.current_x - 1] != '1')
			game->player.current_x--;
		if (game->player.current_x != save_x \
		|| game->player.current_y != save_y)
			new_map(save_x, save_y, game);
		printf("Count: %d\n", ++game->player.moves);
	}
}

void	check_collectibles(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->number_of_collectibles)
	{
		if (game->collectibles[i].x == game->player.current_x
			&& game->collectibles[i].y == game->player.current_y
			&& game->collectibles[i].is_collected == 0)
		{
			game->player.did_collect++;
			game->collectibles[i].is_collected = 1;
		}
		i++;
	}
}

void	check_exit(t_game *game)
{
	if (game->player.did_collect == game->number_of_collectibles)
	{	
		if (game->exit.x == game->player.current_x \
			&& game->exit.y == game->player.current_y)
		{
			game->exit.is_opened = 1;
			printf("!!YOU WIN!!");
			exit(0);
		}
		return ;
	}
}

int	key_press(int key, t_game *game)
{
	if (key == KEY_W || key == KEY_A \
		|| key == KEY_S || key == KEY_D)
	{
		move_check_wall(key, game);
		check_collectibles(game);
		check_exit(game);
	}
	else if (key == KEY_ESC)
	{
		printf("So Long, Farewell~ ");
		exit(0);
	}
	return (0);
}

int	main(void)
{
	t_check	check;
	t_game	game;

	check_init(&check);
	count_hight("mape.ber", &check);
	check_them_all("mape.ber", &check);
	ft_mapping("mape.ber", &check);
	make_2d_map(&check, &game);
	ptr_init(&game);
	image_init(&game);
	init_features(&game);
	draw_map(&game, &check);
	mlx_hook(game.win_ptr, X_EVENT_KEY_PRESS, 0, &key_press, &game);
	mlx_loop(game.mlx_ptr);
	return(0);
}
