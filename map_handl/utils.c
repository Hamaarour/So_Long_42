/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:05:21 by hamaarou          #+#    #+#             */
/*   Updated: 2022/12/24 20:26:46 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * *exit from the game
 */
int	ft_exit(void)
{
	exit(0);
	return (0);
}

void	pp(int count_move, t_map *m)
{
	mlx_put_image_to_window(m->vars.mlx, m->vars.win, m->img.img_wall, 0 * 80, 0
		* 80);
	mlx_string_put(m->vars.mlx, m->vars.win, 20, 20, 0xffffff,
		ft_itoa(count_move));
}

int	key_hook_press(int keycode, t_map *m)
{
	static int	count_move;

	if (keycode == 13 || keycode == 126)
	{
		if (move_up(m))
			ft_printf("You pressed button  UP  move ==> [%d]\n", ++count_move);
	}
	else if (keycode == 0 || keycode == 123)
	{
		if (move_left(m))
			ft_printf("You pressed button  LEFT  move ==> [%d]\n", ++count_move);
	}
	else if (keycode == 1 || keycode == 125)
	{
		if (move_down(m))
			ft_printf("You pressed button  DOWN  move ==> [%d]\n", ++count_move);
	}
	else if (keycode == 2 || keycode == 124)
	{
		if (move_right(m))
			ft_printf("You pressed button  RIGHT move ==> [%d]\n", ++count_move);
	}
	else if (keycode == 53)
		exit(0);
	return (pp(count_move, m), 0);
}

/**
 * *position x & y of the player
 */
void	check_player_position(t_map *map)
{
	int	y;
	int	x;
	int	len_hight;
	int	len_width;
	int	k;

	y = 0;
	while (map->data_map[y])
	{
		x = 0;
		while (map->data_map[y][x])
		{
			if (map->data_map[y][x] == 'P')
			{
				map->player_x = x;
				map->player_y = y;
			}
			x++;
		}
		y++;
	}
	return ;
}
