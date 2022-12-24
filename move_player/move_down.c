/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 00:53:13 by hamaarou          #+#    #+#             */
/*   Updated: 2022/12/24 16:25:43 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
int	move_down(t_map *m)
{
	if (m->data_map[m->player_y + 1][m->player_x] != '1')
	{
		if (m->data_map[m->player_y + 1][m->player_x] == 'C')
		{
			(--m->collectible);
			m->data_map[m->player_y + 1][m->player_x] = '0';
			mlx_put_image_to_window(m->vars.mlx,
									m->vars.win, m->img.img_gr, m->player_x * 80, m->player_y * 80 + 80);
		}
		mlx_put_image_to_window(m->vars.mlx, m->vars.win, m->img.img_gr,
				m->player_x * 80, m->player_y * 80);
		mlx_put_image_to_window(m->vars.mlx, m->vars.win, m->img.img_player,
				m->player_x * 80, m->player_y * 80 + 80);
		m->player_y += 1;
		return (1);
	}
	return (0);
}
