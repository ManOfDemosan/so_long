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
		printf("x: %d y: %d\n", check->img->img_ptr_P->x, check->img->img_ptr_P->y);
		if (key == KEY_W || key == KEY_S || key == KEY_A || key == KEY_D)
			printf("Count: %d\n", ++check->img->img_ptr_P->moves);
	}
}

void	check_collectible(t_check *check)
{
	int	i;

	i = 0;
	while (i < check->num_c)
	{
		if (check->img->img_ptr_C[i].x == check->img->img_ptr_P->x \
		&& check->img->img_ptr_C[i].y == check->img->img_ptr_P->y \
		&& check->img->img_ptr_C[i].flag == 0)
		{
			check->img->img_ptr_P->flag++;
			check->img->img_ptr_C[i].flag = 1;
		}
		i++;
	}
}

void	check_exit(t_check *check)
{
	if (check->img->img_ptr_P->flag != check->num_c)
		return ;
	if (check->img->img_ptr_E->x == check->img->img_ptr_P->x \
		&& check->img->img_ptr_E->y == check->img->img_ptr_P->y)
	{
		check->img->img_ptr_E->flag = 1;
		printf("!!YOU WIN!!");
		exit(0);
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