/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:58:37 by hamaarou          #+#    #+#             */
/*   Updated: 2023/01/05 22:24:57 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	norm(t_map *map, int x, int y, char n)
{
	if (n == '1')
		mlx_put_image_to_window(map->vars.mlx, map->vars.win, map->img.img_wall,
			x * 80, y * 80);
	else if (n == '0')
		mlx_put_image_to_window(map->vars.mlx, map->vars.win, map->img.img_gr, x
			* 80, y * 80);
}

void	norm_two(t_map *map, int x, int y, char n)
{
	if (n == 'P')
	{
		mlx_put_image_to_window(map->vars.mlx, map->vars.win, map->img.img_gr, x
			* 80, y * 80);
		mlx_put_image_to_window(map->vars.mlx, map->vars.win,
			map->img.img_player, x * 80, y * 80);
	}
	else if (n == 'E')
	{
		mlx_put_image_to_window(map->vars.mlx, map->vars.win, map->img.img_gr, x
			* 80, y * 80);
		mlx_put_image_to_window(map->vars.mlx, map->vars.win, map->img.img_exit,
			x * 80, y * 80);
	}
}

void	render_map(t_map *map)
{
	int	y;
	int	x;

	y = -1;
	while (map->data_map[++y])
	{
		x = -1;
		while (map->data_map[y][++x])
		{
			if (map->data_map[y][x] == '1')
				norm(map, x, y, '1');
			else if (map->data_map[y][x] == '0')
				norm(map, x, y, '0');
			else if (map->data_map[y][x] == 'P')
				norm_two(map, x, y, 'P');
			else if (map->data_map[y][x] == 'E')
				norm_two(map, x, y, 'E');
		}
	}
}
