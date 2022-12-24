/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 00:53:35 by hamaarou          #+#    #+#             */
/*   Updated: 2022/12/24 01:00:54 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_right(t_map *m)
{
	if (m->data_map[m->player_y][m->player_x + 1] != '1')
	{
		mlx_put_image_to_window(m->vars.mlx, m->vars.win, m->img.img_gr,
				m->player_x * 80, m->player_y * 80);
		mlx_put_image_to_window(m->vars.mlx, m->vars.win, m->img.img_player,
				m->player_x * 80 + 80, m->player_y * 80);
		m->player_x += 1;
	}
}
