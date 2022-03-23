/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:30:14 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/03/23 20:40:03 by jaehwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "mlx.h"
#include "./map/map.h"

void	draw_land_river(t_ptr *ptr, t_img *img, t_param *param, t_check *check)
{
	int		i;
	int		j;

	i = 0;
	while (check->map[i] != NULL)
	{
		param->x = 0;
		j = 0;
		while (check->map[i][j] != '\n')
		{
			if (check->map[i][j] == '1')
				mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, \
				img->img_ptr_1->img, param->x, param->y);
			else if (check->map[i][j] == '0')
				mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, \
				img->img_ptr_0->img, param->x, param->y);
			j++;
			param->x += 64;
		}
		i++;
		param->y += 64;
	}
	param->y = 0;
	param->x = 0;
}

void	draw_player(t_ptr *ptr, t_img *img, t_param *param, t_check *check)
{
	int		i;
	int		j;

	i = 0;
	while (check->map[i] != NULL)
	{
		param->x = 0;
		j = 0;
		while (check->map[i][j] != '\n')
		{
			if (check->map[i][j] == 'P')
				mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, \
					img->img_ptr_P->img, param->x, param->y);
			j++;
			param->x += 64;
		}
		i++;
		param->y += 64;
	}
	param->y = 0;
	param->x = 0;
}

void	draw_collectable(t_ptr *ptr, t_img *img, t_param *param, t_check *check)
{
	int		i;
	int		j;

	i = 0;
	while (check->map[i] != NULL)
	{
		param->x = 0;
		j = 0;
		while (check->map[i][j] != '\n')
		{
			if (check->map[i][j] == 'C')
				mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, \
					img->img_ptr_C->img, param->x, param->y);
			j++;
			param->x += 64;
		}
		i++;
		param->y += 64;
	}
	param->y = 0;
	param->x = 0;
}

void	draw_exit(t_ptr *ptr, t_img *img, t_param *param, t_check *check)
{
	int		i;
	int		j;

	i = 0;
	while (check->map[i] != NULL)
	{
		param->x = 0;
		j = 0;
		while (check->map[i][j] != '\n')
		{
			if (check->map[i][j] == 'E')
				mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, \
				img->img_ptr_E->img, param->x, param->y);
			j++;
			param->x += 64;
		}
		i++;
		param->y += 64;
	}
	param->y = 0;
	param->x = 0;
}


void	draw_map(t_ptr *ptr, t_img *img, t_param *param, t_check *check)
{
	draw_land_river(ptr, img, param, check);
	draw_player(ptr, img, param, check);
	draw_collectable(ptr, img, param, check);
	draw_exit(ptr, img, param, check);
}
