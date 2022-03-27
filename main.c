/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:11:22 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/03/27 20:35:50 by jaehwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	terminate_game(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	printf("So Long, Farewell~\n");
	exit(0);
	return (0);
}

int	main(void)
{
	t_check	check;
	t_game	game;

	check_init(&check);
	check_and_save_map("mape.ber", &check);
	print_map(&game, &check);
	init_features(&game);
	draw_map(&game, &check);
	mlx_hook(game.win_ptr, X_EVENT_KEY_PRESS, 0, &key_press, &game);
	mlx_hook(game.win_ptr, X_EVENT_KEY_EXIT, 0, &terminate_game, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
