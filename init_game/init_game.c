/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 20:29:47 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/03/28 16:36:53 by jaehwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

void	print_map(t_game *game, t_check *check)
{
	make_2d_map(check, game);
	ptr_init(game);
	image_init(game);
}
