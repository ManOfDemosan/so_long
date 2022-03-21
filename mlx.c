/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:11:22 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/03/18 17:31:49 by jaehwkim         ###   ########.fr       */
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

int	main(void)
{
	char	**map;
	
	t_check	check;
	check.status = 0;
	check.width = 0;
	check.height = 0;
	check.num_p = 0;
	check.num_c = 0;
	check.num_e = 0;


	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr1;
	void	*img_ptr2;
	void	*img_ptr_P;
	void	*img_ptr_C;
	void	*img_ptr_E;
	int		x_size;
	int		y_size;

	int     x;
	int 	y;
	int		i;
	int		j;
	
	count_hight("mape.ber", &check);
	check_them_all("mape.ber", &check);
	map = ft_mapping("mape.ber", &check);
	
	
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 640, 320, "choon!");
	img_ptr1 = mlx_xpm_file_to_image(mlx_ptr, "./cat64.xpm", &x_size,  &y_size);
	img_ptr2 = mlx_xpm_file_to_image(mlx_ptr, "./choon64.xpm", &x_size,  &y_size);
	img_ptr_P = mlx_xpm_file_to_image(mlx_ptr, "./P64.xpm", &x_size,  &y_size);
	img_ptr_C = mlx_xpm_file_to_image(mlx_ptr, "./C64.xpm", &x_size,  &y_size);
	img_ptr_E = mlx_xpm_file_to_image(mlx_ptr, "./E64.xpm", &x_size,  &y_size);
	i = 0;
	if (check.status == SUCCESS)
	printf("SUCCESS!\n");
	if (check.status == FAILURE)
	printf("FAILURE!\n");
	while (map[i] != NULL)
	{
		printf("%s", map[i]);
		i++;
	}
	y = 0;
	i = 0;
	while (map[i] != NULL)
	{
		x = 0;
		j = 0;
		while (map[i][j] != '\n')
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(mlx_ptr, win_ptr,img_ptr2, x, y);
			else if (map[i][j] == '0')
				mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr1, x, y);
			else if (map[i][j] == 'C')
				mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr_C, x, y);
			else if (map[i][j] == 'P')
				mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr_P, x, y);
			else if (map[i][j] == 'E')
				mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr_E, x, y);
			j++;
			x += 64;	
		}
		i++;
		y += 64;
	}
	
	mlx_loop(mlx_ptr);
	return(0);
}
