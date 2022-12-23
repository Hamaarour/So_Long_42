/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:08:38 by hamaarou          #+#    #+#             */
/*   Updated: 2022/12/23 23:23:58 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// void	move_up(t_map *m)
// {
// 	if (m->data_map[m->player_y - 1][m->player_x] == '0')
// 	{
// 		// m->data_map[m->player_y][m->player_x] = '0';
// 		// m->data_map[m->player_y - 1][m->player_x] = 'P';
// 		mlx_put_image_to_window(m->vars->mlx, m->vars->win, m->img->img_player,
// 				(m->player_y - 1) * 80, (m->player_x) * 80);
// 		mlx_put_image_to_window(m->vars->mlx, m->vars->win, m->img->img_gr,
// 				(m->player_y) * 80, (m->player_x) * 80);
// 		m->player_y -= 1;
// 	}
// 	else
// 		printf("there is a wall\n");
// }
