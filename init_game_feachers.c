/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_feachers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:53:54 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/03/27 20:36:59 by jaehwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
