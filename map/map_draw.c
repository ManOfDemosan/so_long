/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:30:14 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/03/28 16:37:07 by jaehwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_land_river(t_game *game, t_check *check)
{
	int		i;
	int		j;

	i = 0;
	while (check->map[i] != NULL)
	{
		j = 0;
		while (check->map[i][j] != '\n' && check->map[i][j] != '\0')
		{
			if (check->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
				game->tiles.wall.image_pointer, j * TILE_SIZE, i * TILE_SIZE);
			else
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
				game->tiles.space.image_pointer, j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
}

void	draw_player(t_game *game, t_check *check)
{
	int		i;
	int		j;

	i = 0;
	while (check->map[i] != NULL)
	{
		j = 0;
		while (check->map[i][j] != '\n' && check->map[i][j] != '\0')
		{
			if (check->map[i][j] == 'P')
			{
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
				game->tiles.player.image_pointer, j * TILE_SIZE, i * TILE_SIZE);
			}
			j++;
		}
		i++;
	}
}

void	draw_collectable(t_game *game, t_check *check)
{
	int		i;
	int		j;
	int		x;

	i = 0;
	x = 0;
	while (check->map[i] != NULL)
	{
		j = 0;
		while (check->map[i][j] != '\n' && check->map[i][j] != '\0')
		{
			if (check->map[i][j] == 'C')
			{
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
					game->tiles.collectible.image_pointer, \
					j * TILE_SIZE, i * TILE_SIZE);
			}
			j++;
		}
		i++;
	}
}

void	draw_exit(t_game *game, t_check *check)
{
	int		i;
	int		j;

	i = 0;
	while (check->map[i] != NULL)
	{
		j = 0;
		while (check->map[i][j] != '\n' && check->map[i][j] != '\0')
		{
			if (check->map[i][j] == 'E')
			{
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
				game->tiles.exit.image_pointer, j * TILE_SIZE, i * TILE_SIZE);
			}
			j++;
		}
		i++;
	}
}

void	draw_map(t_game *game, t_check *check)
{
	draw_land_river(game, check);
	draw_player(game, check);
	draw_collectable(game, check);
	draw_exit(game, check);
}
