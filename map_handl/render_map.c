/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:58:37 by hamaarou          #+#    #+#             */
/*   Updated: 2022/12/22 22:38:26 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	render_map(t_img *img, t_vars *vars, char *argv, t_map *map)
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
				mlx_put_image_to_window(vars->mlx, vars->win,
					img->img_wall, x * 50, y * 50);
			else if (map->data_map[y][x] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win,
					img->img_gr, x * 50, y * 50);
			else if (map->data_map[y][x] == 'C')
			{
				mlx_put_image_to_window(vars->mlx, vars->win,
					img->img_gr, x * 50, y * 50);
				mlx_put_image_to_window(vars->mlx, vars->win,
					img->img_collect, x * 50, y * 50);
			}
			else if (map->data_map[y][x] == 'P')
			{
				mlx_put_image_to_window(vars->mlx, vars->win,
					img->img_gr, x * 50, y * 50);
				mlx_put_image_to_window(vars->mlx, vars->win,
					img->img_player, x * 50, y * 50);
			}
			else if (map->data_map[y][x] == 'E')
			{
				mlx_put_image_to_window(vars->mlx, vars->win,
					img->img_gr, x * 50, y * 50);
				mlx_put_image_to_window(vars->mlx, vars->win,
					img->img_exit, x * 50, y * 50);
			}
		}
	}
}
