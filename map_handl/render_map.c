/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:58:37 by hamaarou          #+#    #+#             */
/*   Updated: 2022/12/22 15:05:41 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	render_map(t_img *img, t_vars *vars, char *argv)
{
	int fd;
	char *str;
	int y;
	int x;

	y = 0;
	fd = open(argv, O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
	{
		x = 0;
		while (str[x])
		{
			if (str[x] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, img->img_wall, x
						* 50, y * 50);
			else if (str[x] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win, img->img_gr, x
						* 50, y * 50);
			else if (str[x] == 'C')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, img->img_gr, x
						* 50, y * 50);
				mlx_put_image_to_window(vars->mlx, vars->win, img->img_collect,
						x * 50, y * 50);
			}
			else if (str[x] == 'P')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, img->img_gr, x
						* 50, y * 50);
				mlx_put_image_to_window(vars->mlx, vars->win, img->img_player, x
						* 50, y * 50);
			}
			else if (str[x] == 'E')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, img->img_gr, x
						* 50, y * 50);
				mlx_put_image_to_window(vars->mlx, vars->win, img->img_exit, x
						* 50, y * 50);
			}
			x++;
		}
		y++;
	}
}