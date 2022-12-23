/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:58:37 by hamaarou          #+#    #+#             */
/*   Updated: 2022/12/24 00:12:12 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
				mlx_put_image_to_window(map->vars.mlx, map->vars.win,
						map->img.img_wall, x * 80, y * 80);
			else if (map->data_map[y][x] == '0')
				mlx_put_image_to_window(map->vars.mlx, map->vars.win,
						map->img.img_gr, x * 80, y * 80);
			else if (map->data_map[y][x] == 'C')
			{
				mlx_put_image_to_window(map->vars.mlx, map->vars.win,
						map->img.img_gr, x * 80, y * 80);
				mlx_put_image_to_window(map->vars.mlx, map->vars.win,
						map->img.img_collect, x * 80, y * 80);
			}
			else if (map->data_map[y][x] == 'P')
			{
				mlx_put_image_to_window(map->vars.mlx, map->vars.win,
						map->img.img_gr, x * 80, y * 80);
				mlx_put_image_to_window(map->vars.mlx, map->vars.win,
						map->img.img_player, x * 80, y * 80);
			}
			else if (map->data_map[y][x] == 'E')
			{
				mlx_put_image_to_window(map->vars.mlx, map->vars.win,
						map->img.img_gr, x * 80, y * 80);
				mlx_put_image_to_window(map->vars.mlx, map->vars.win,
						map->img.img_exit, x * 80, y * 80);
			}
		}
	}
}
