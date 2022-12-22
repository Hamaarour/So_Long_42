/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:05:21 by hamaarou          #+#    #+#             */
/*   Updated: 2022/12/22 22:24:53 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_map_path(char *map_path)
{
	int		len;
	char	*s;

	len = ft_strlen(map_path);
	s = &map_path[(len - 4)];
	if (ft_strncmp(s, ".ber", 4) == 0)
		return (1);
	return (0);
}

int	ft_exit(void)
{
	exit(0);
	return (0);
}

int	key_hook_press(int keycode, void *param)
{
	static int	count_move;

	if (keycode == 13 || keycode == 126)
		ft_printf("You pressed button   UP   move ==> [%d]\n", ++count_move);
	else if (keycode == 0 || keycode == 123)
		ft_printf("You pressed button  LEFT  move ==> [%d]\n", ++count_move);
	else if (keycode == 1 || keycode == 125)
		ft_printf("You pressed button  DOWN  move ==> [%d]\n", ++count_move);
	else if (keycode == 2 || keycode == 124)
		ft_printf("You pressed button  RIGHT move ==> [%d]\n", ++count_move);
	else if (keycode == 53)
		exit(0);
	return (0);
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
