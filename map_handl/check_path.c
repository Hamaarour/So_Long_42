/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:58:31 by hamaarou          #+#    #+#             */
/*   Updated: 2023/01/05 17:05:44 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	path_tracking_coin(t_map *map, int y, int x)
{
	if (x < 0 || x >= map->width || y < 0 || y >= map->height)
		return (0);
	if (map->map_c[y][x] == '1'
	|| map->map_c[y][x] == 'E' || map->map_c[y][x] == 'N')
		return (0);
	if (map->map_c[y][x] == 'C')
		map->refer_coin += 1;
	map->map_c[y][x] = '1';
	if (path_tracking_coin(map, y, x - 1))
		return (1);
	if (path_tracking_coin(map, y, x + 1))
		return (1);
	if (path_tracking_coin(map, y - 1, x))
		return (1);
	if (path_tracking_coin(map, y + 1, x))
		return (1);
	return (0);
}

int	path_tracking_exit(t_map *map, int y, int x)
{
	if (x < 0 || x >= map->width || y < 0 || y >= map->height)
		return (0);
	if (map->map_e[y][x] == '1' || map->map_e[y][x] == 'N')
		return (0);
	if (map->map_e[y][x] == 'E')
		return (0);
	map->map_e[y][x] = '1';
	if (path_tracking_coin(map, y, x - 1))
		return (1);
	if (path_tracking_coin(map, y, x + 1))
		return (1);
	if (path_tracking_coin(map, y - 1, x))
		return (1);
	if (path_tracking_coin(map, y + 1, x))
		return (1);
	return (0);
}

int	check_path(t_map *map)
{
	map->refer_coin = 0;
	map->map_c = ft_split(map->lines, '\n');
	map->map_e = ft_split(map->lines, '\n');
	check_p(map, &(map->pl));
	path_tracking_coin(map, map->pl.player_y, map->pl.player_x);
	path_tracking_exit(map, map->pl.player_y, map->pl.player_x);
	if (map->collectible != map->refer_coin)
	{
		ft_printf("ERROR!\nPath misconfguered");
		exit(1);
	}
	return (0);
}
