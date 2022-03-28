/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_keypress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 20:14:38 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/03/28 02:34:03 by jaehwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	new_map(int x, int y, t_game *game)
{
	if (game->exit.is_opened != 1 && x == game->exit.x && y == game->exit.y)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->tiles.exit.image_pointer, x * TILE_SIZE, y * TILE_SIZE);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->tiles.player.image_pointer, \
		game->player.current_x * TILE_SIZE, game->player.current_y * TILE_SIZE);
	}
	else
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->tiles.space.image_pointer, x * TILE_SIZE, y * TILE_SIZE);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->tiles.player.image_pointer, \
		game->player.current_x * TILE_SIZE, game->player.current_y * TILE_SIZE);
	}
}

void	move_check_wall(int key, t_game *game)
{
	int	save_x;
	int	save_y;

	save_x = game->player.current_x;
	save_y = game->player.current_y;
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
	if (game->player.did_collect != game->number_of_collectibles)
		return ;
	if (game->exit.x == game->player.current_x \
			&& game->exit.y == game->player.current_y)
	{
		game->exit.is_opened = 1;
		printf("!!YOU WIN!!");
		exit(0);
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
