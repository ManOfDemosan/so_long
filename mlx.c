/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:11:22 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/03/21 22:00:13 by jaehwkim         ###   ########.fr       */
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

// void	ft_putchar(char c)
// {
// 	write(1, &c, 1);
// }

// int	deal_key(int key, void *param)
// {
// 	ft_putchar('O');
// 	return (0);
// }

void	check_init(t_check *check)
{
	check->status = 0;
	check->width = 0;
	check->height = 0;
	check->num_p = 0;
	check->num_c = 0;
	check->num_e = 0;
}

void image_init(t_img *img, t_ptr *ptr)
{
	int		width;
	int		height;
	
	img->img_ptr0 = malloc(sizeof(t_info) * 1);
	img->img_ptr1 = malloc(sizeof(t_info) * 1);
	img->img_ptr_P = malloc(sizeof(t_info) * 1);
	img->img_ptr_C = malloc(sizeof(t_info) * 1);
	img->img_ptr_E = malloc(sizeof(t_info) * 1);
	
	img->img_ptr0->img = mlx_xpm_file_to_image(ptr->mlx_ptr, "./0.64.xpm", &width, &height);
	img->img_ptr1->img = mlx_xpm_file_to_image(ptr->mlx_ptr, "./1.64.xpm", &width, &height);
	img->img_ptr_P->img = mlx_xpm_file_to_image(ptr->mlx_ptr, "./P64.xpm", &width, &height);
	img->img_ptr_C->img = mlx_xpm_file_to_image(ptr->mlx_ptr, "./C64.xpm", &width, &height);
	img->img_ptr_E->img = mlx_xpm_file_to_image(ptr->mlx_ptr, "./E64.xpm", &width, &height);

}
void _ptr(t_ptr *ptr)
{
	ptr->mlx_ptr = mlx_init();
	ptr->win_ptr = mlx_new_window(ptr->mlx_ptr, 896, 320, "choon!");
}

int	main()
{
	char	**map;
	t_check	check;
	t_ptr	ptr;
	t_img	*img;
	
	_ptr(&ptr);
	check_init(&check);
	img = malloc(sizeof (t_img) * 1);
	image_init(img, &ptr);
	
	count_hight("mape.ber", &check);
	check_them_all("mape.ber", &check);
	map = ft_mapping("mape.ber", &check);

	int     x;
	int 	y;
	int		i;
	int		j;

	y = 0;
	i = 0;
	while (map[i] != NULL)
	{
		x = 0;
		j = 0;
		while (map[i][j] != '\n')
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(ptr.mlx_ptr, ptr.win_ptr, img->img_ptr1->img, x, y);
			else if (map[i][j] == '0')
				mlx_put_image_to_window(ptr.mlx_ptr, ptr.win_ptr, img->img_ptr0->img, x, y);
			else if (map[i][j] == 'C')
				mlx_put_image_to_window(ptr.mlx_ptr, ptr.win_ptr, img->img_ptr_C->img, x, y);
			else if (map[i][j] == 'P')
				mlx_put_image_to_window(ptr.mlx_ptr, ptr.win_ptr, img->img_ptr_P->img, x, y);
			else if (map[i][j] == 'E')
				mlx_put_image_to_window(ptr.mlx_ptr, ptr.win_ptr, img->img_ptr_E->img, x, y);
			j++;
			x += 64;	
		}
		i++;
		y += 64;
	}
	
	mlx_loop(ptr.mlx_ptr);
	return(0);
}
