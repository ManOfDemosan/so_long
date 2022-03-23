/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:11:22 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/03/23 22:37:45 by jaehwkim         ###   ########.fr       */
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
	check->status = 0;
	check->width = 0;
	check->height = 0;
	check->num_p = 0;
	check->num_c = 0;
	check->num_e = 0;
}

void	image_init(t_img *img, t_ptr *ptr)
{
	int		width;
	int		height;

	img->img_ptr_0 = malloc(sizeof(t_info) * 1);
	img->img_ptr_1 = malloc(sizeof(t_info) * 1);
	img->img_ptr_P = malloc(sizeof(t_info) * 1);
	img->img_ptr_C = malloc(sizeof(t_info) * 1);
	img->img_ptr_E = malloc(sizeof(t_info) * 1);
	img->img_ptr_0->img = mlx_xpm_file_to_image(ptr->mlx_ptr, \
	"./xpm/0.64.xpm", &width, &height);
	img->img_ptr_1->img = mlx_xpm_file_to_image(ptr->mlx_ptr, \
	"./xpm/1.64.xpm", &width, &height);
	img->img_ptr_P->img = mlx_xpm_file_to_image(ptr->mlx_ptr, \
	"./xpm/P64.xpm", &width, &height);
	img->img_ptr_C->img = mlx_xpm_file_to_image(ptr->mlx_ptr, \
	"./xpm/C64.xpm", &width, &height);
	img->img_ptr_E->img = mlx_xpm_file_to_image(ptr->mlx_ptr, \
	 "./xpm/E64.xpm", &width, &height);
}

void	ptr_init(t_ptr *ptr, t_check *check)
{
	ptr->mlx_ptr = mlx_init();
	ptr->win_ptr = mlx_new_window(ptr->mlx_ptr, \
		check->width * 64, check->height * 64, "choon!");
}

void	param_init(t_param *param)
{
	param->x = 0;
	param->y = 0;
	param->moves = 0;
}

int	key_press(int key, t_param *param)
{

	if (key != KEY_ESC)
	{
		if (key == KEY_W)
			param->y++;
		else if (key == KEY_S)
			param->y--;
		else if (key == KEY_D)
			param->x++;
		else if (key == KEY_A)
			param->x--;
		printf("x: %d y: %d\n", param->x, param->y);
		if (key == KEY_W || key == KEY_S || key == KEY_A || key == KEY_D)
		{
			param->moves++;
			printf("Count: %d\n", param->moves);
		}
	}
	if (key == KEY_ESC)
	{
		printf("So Long, Farewell~ ");
		exit(0);
	}
	return (0);
}

int	main(void)
{

	int key = 3;
	t_check	check;
	t_ptr	ptr;
	t_img	*img;
	t_param	param;

	check_init(&check);
	count_hight("mape.ber", &check);
	check_them_all("mape.ber", &check);
	ft_mapping("mape.ber", &check);

	ptr_init(&ptr, &check);

	img = malloc(sizeof (t_img) * 1);
	image_init(img, &ptr);
	param_init(&param);

	key_press(key, &param);
	draw_map(&ptr, img, &param, &check);

	mlx_hook(ptr.win_ptr, X_EVENT_KEY_PRESS, 0, &key_press, &param);
	mlx_loop(ptr.mlx_ptr);
	return(0);
}
