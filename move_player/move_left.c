/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 00:53:41 by hamaarou          #+#    #+#             */
/*   Updated: 2022/12/24 20:28:07 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	move_left(t_map *m)
{
	if ((m->data_map[m->player_y][m->player_x - 1] != '1'
		&& m->data_map[m->player_y][m->player_x - 1] != 'E')
			|| door_open(m,
			m->player_y, m->player_x - 1))
	{
		if (m->data_map[m->player_y][m->player_x - 1] == 'C')
		{
			(--m->collectible);
			m->data_map[m->player_y][m->player_x - 1] = '0';
			mlx_put_image_to_window(m->vars.mlx, m->vars.win, m->img.img_gr,
				m->player_x * 80 - 80, m->player_y * 80);
		}
		mlx_put_image_to_window(m->vars.mlx, m->vars.win, m->img.img_gr,
			m->player_x * 80, m->player_y * 80);
		mlx_put_image_to_window(m->vars.mlx, m->vars.win, m->img.img_player,
			m->player_x * 80 - 80, m->player_y * 80);
		m->player_x -= 1;
		return (1);
	}
	return (0);
}
