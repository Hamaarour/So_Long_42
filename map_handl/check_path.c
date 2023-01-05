/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:58:31 by hamaarou          #+#    #+#             */
/*   Updated: 2023/01/05 13:46:23 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	path_tracking_coin(t_map *map, int y, int x)
{
	t_ply pl;
	check_p(map, &pl);
	if (x < 0 || x > map->width || y < 0 || y > map->height)
		return;
	// printf("fake = %d\n", map->width);
	printf("px = %d py = %d\n", x, y);
	printf("%c\n", map->map_c[y][x]);
	if (map->map_c[y][x] == '1' || map->map_c[y][x] == 'E')
		return ;
	if (map->map_c[y][x] == 'C')
	{
		printf("IM HERE\n");
		map->refer_coin += 1;
	}
	map->map_c[y][x] = 'Z';
	path_tracking_coin(map, y, x - 1);
	path_tracking_coin(map, y, x + 1);
	path_tracking_coin(map, y - 1, x);
	path_tracking_coin(map, y + 1, x);
}

int	check_path(t_map *map)
{
	map->refer_coin = 0;
	map->map_c = ft_split(map->lines, '\n');
	map->map_e = ft_split(map->lines, '\n');
	path_tracking_coin(map, map->pl.player_y, map->pl.player_x);
	printf("pyy = %d pyx = %d\n", map->pl.player_y, map->pl.player_x);
	if (map->collectible != map->refer_coin)
	{
		ft_printf("ERROR!\nPath misconfguered");
		exit(1);
	}
	return (0);
}
