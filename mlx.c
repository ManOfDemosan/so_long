/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:11:22 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/03/25 21:09:52 by jaehwkim         ###   ########.fr       */
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

void	info_init(t_img *img)
{
	img->img_ptr_P->moves = 0;
	img->img_ptr_C->flag = 0;
	img->img_ptr_E->flag = 0;
	img->img_ptr_P->flag = 0;
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
}

void	move_check_wall(int key, t_check *check)
{
	int	save_x;
	int	save_y;

	save_x = check->img->img_ptr_P->x;
	save_y = check->img->img_ptr_P->y;
	if (key != KEY_ESC)
	{
		if (key == KEY_W
			&& check->map[check->img->img_ptr_P->y - 1][check->img->img_ptr_P->x] != '1')
			check->img->img_ptr_P->y--;
		else if (key == KEY_S
			&& check->map[check->img->img_ptr_P->y + 1][check->img->img_ptr_P->x] != '1')
			check->img->img_ptr_P->y++;
		else if (key == KEY_D
			&& check->map[check->img->img_ptr_P->y][check->img->img_ptr_P->x + 1] != '1')
			check->img->img_ptr_P->x++;
		else if (key == KEY_A
			&& check->map[check->img->img_ptr_P->y][check->img->img_ptr_P->x - 1] != '1')
			check->img->img_ptr_P->x--;
		if (check->img->img_ptr_P->x != save_x || check->img->img_ptr_P->y != save_y)
			printf("Count: %d\n", ++check->img->img_ptr_P->moves);
	}
}

void	check_collectible(t_check *check)
{
	int	i;

	i = 0;
	while (i < check->num_c)
	{
		if (check->img->img_ptr_C[i].x == check->img->img_ptr_P->x
			&& check->img->img_ptr_C[i].y == check->img->img_ptr_P->y
			&& check->img->img_ptr_C[i].flag == 0)
		{
			check->img->img_ptr_P->flag++;
			check->img->img_ptr_C->flag = 1;
		}
		i++;
	}
}

void	check_exit(t_check *check)
{

	if (check->img->img_ptr_P->flag == check->num_c)
	{	
			
		if (check->img->img_ptr_E->x == check->img->img_ptr_P->x \
			&& check->img->img_ptr_E->y == check->img->img_ptr_P->y)
		{
			check->img->img_ptr_E->flag = 1;
			printf("!!YOU WIN!!");
			exit(0);
		}
		return ;
	}
	
}

int	key_press(int key, t_check *check)
{
	if (key == KEY_W || key == KEY_A \
		|| key == KEY_S || key == KEY_D)
	{
		move_check_wall(key, check);
		check_collectible(check);
		check_exit(check);
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
	t_ptr	ptr;
	t_img	img;
	t_param	param;

	
	
	check_init(&check);
	count_hight("mape.ber", &check);
	check_them_all("mape.ber", &check);
	ft_mapping("mape.ber", &check);

	ptr_init(&ptr, &check);
	
	image_init(&img, &ptr);
	info_init(&img);
	param_init(&param);

	draw_map(&ptr, &img, &param, &check);
	check.img = &img;
	mlx_hook(ptr.win_ptr, X_EVENT_KEY_PRESS, 0, &key_press, &check);
	mlx_loop(ptr.mlx_ptr);
	return(0);
}
