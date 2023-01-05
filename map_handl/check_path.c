/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:58:31 by hamaarou          #+#    #+#             */
/*   Updated: 2023/01/05 21:34:14 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	exit_pos(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->data_map[y])
	{
		x = 0;
		while (map->data_map[y][x])
		{
			if (map->data_map[y][x] == 'E')
			{
				map->ex_pos.ex_x = x;
				map->ex_pos.ex_y = y;
			}
			x++;
		}
		y++;
	}
}

void	path_tracking_coin(t_map *map, int y, int x)
{
	if (x < 0 || x >= map->width || y < 0 || y >= map->height)
		return ;
	if (map->map_c[y][x] == '1'
	|| map->map_c[y][x] == 'E' || map->map_c[y][x] == 'N')
		return ;
	if (map->map_c[y][x] == 'C')
		map->refer_coin += 1;
	map->map_c[y][x] = '1';
	path_tracking_coin(map, y, x - 1);
	path_tracking_coin(map, y, x + 1);
	path_tracking_coin(map, y - 1, x);
	path_tracking_coin(map, y + 1, x);
}

void	path_tracking_exit(t_map *map, int y, int x)
{
	if (x < 0 || x >= map->width || y < 0 || y >= map->height)
		return ;
	if (map->map_e[y][x] == '1' || map->map_e[y][x] == 'N')
		return ;
	if (map->map_e[y][x] == 'E')
		map->refer_exit++;
	map->map_e[y][x] = '1';
	path_tracking_exit(map, y, x - 1);
	path_tracking_exit(map, y, x + 1);
	path_tracking_exit(map, y - 1, x);
	path_tracking_exit(map, y + 1, x);
}

int	check_path(t_map *map)
{
	map->refer_coin = 0;
	map->refer_exit = 0;
	map->map_c = ft_split(map->lines, '\n');
	map->map_e = ft_split(map->lines, '\n');
	check_p(map, &(map->pl));
	exit_pos(map);
	path_tracking_coin(map, map->pl.player_y, map->pl.player_x);
	path_tracking_exit(map, map->pl.player_y, map->pl.player_x);
	if (map->collectible != map->refer_coin || map->refer_exit != 1)
	{
		ft_printf("ERROR!\nPath misconfguered");
		exit(1);
	}
	return (0);
}
