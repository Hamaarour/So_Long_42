/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 00:53:41 by hamaarou          #+#    #+#             */
/*   Updated: 2023/01/05 23:15:07 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	move_left(t_map *m)
{
	if ((m->data_map[m->pl.player_y][m->pl.player_x - 1] != '1'
		&& m->data_map[m->pl.player_y][m->pl.player_x - 1] != 'E')
			|| door_open(m, m->pl.player_y, m->pl.player_x - 1))
	{
		if (m->data_map[m->pl.player_y][m->pl.player_x - 1] == 'N')
			lose();
		if (m->data_map[m->pl.player_y][m->pl.player_x - 1] == 'C')
		{
			(--m->collectible);
			m->data_map[m->pl.player_y][m->pl.player_x - 1] = '0';
			mlx_put_image_to_window(m->vars.mlx, m->vars.win, m->img.img_exit,
				m->pl.player_x * 80 - 80, m->pl.player_y * 80);
			m->data_map[m->pl.player_y][m->pl.player_x - 1] = '0';
			mlx_put_image_to_window(m->vars.mlx, m->vars.win, m->img.img_gr,
				m->pl.player_x * 80 - 80, m->pl.player_y * 80);
		}
		mlx_put_image_to_window(m->vars.mlx, m->vars.win, m->img.img_gr,
			m->pl.player_x * 80, m->pl.player_y * 80);
		mlx_put_image_to_window(m->vars.mlx, m->vars.win, m->img.img_player,
			m->pl.player_x * 80 - 80, m->pl.player_y * 80);
		m->pl.player_x -= 1;
		return (1);
	}
	return (0);
}

int	move_down(t_map *m)
{
	if ((m->data_map[m->pl.player_y + 1][m->pl.player_x] != '1'
		&& m->data_map[m->pl.player_y + 1][m->pl.player_x] != 'E')
		|| door_open(m,
			m->pl.player_y + 1, m->pl.player_x))
	{
		if (m->data_map[m->pl.player_y + 1][m->pl.player_x] == 'N')
			lose();
		if (m->data_map[m->pl.player_y + 1][m->pl.player_x] == 'C')
		{
			(--m->collectible);
			m->data_map[m->pl.player_y + 1][m->pl.player_x] = '0';
			mlx_put_image_to_window(m->vars.mlx,
				m->vars.win,
				m->img.img_gr,
				m->pl.player_x * 80,
				m->pl.player_y * 80 + 80);
		}
		mlx_put_image_to_window(m->vars.mlx, m->vars.win, m->img.img_gr,
			m->pl.player_x * 80, m->pl.player_y * 80);
		mlx_put_image_to_window(m->vars.mlx, m->vars.win, m->img.img_player,
			m->pl.player_x * 80, m->pl.player_y * 80 + 80);
		m->pl.player_y += 1;
		return (1);
	}
	return (0);
}

int	move_right(t_map *m)
{
	if ((m->data_map[m->pl.player_y][m->pl.player_x + 1] != '1'
		&& m->data_map[m->pl.player_y][m->pl.player_x + 1] != 'E')
		|| door_open(m,
			m->pl.player_y, m->pl.player_x + 1))
	{
		if (m->data_map[m->pl.player_y][m->pl.player_x + 1] == 'N')
			lose();
		if (m->data_map[m->pl.player_y][m->pl.player_x + 1] == 'C')
		{
			(--m->collectible);
			m->data_map[m->pl.player_y][m->pl.player_x + 1] = '0';
			mlx_put_image_to_window(m->vars.mlx, m->vars.win, m->img.img_gr,
				m->pl.player_x * 80 + 80, m->pl.player_y * 80);
		}
		mlx_put_image_to_window(m->vars.mlx, m->vars.win, m->img.img_gr,
			m->pl.player_x * 80, m->pl.player_y * 80);
		mlx_put_image_to_window(m->vars.mlx, m->vars.win, m->img.img_player,
			m->pl.player_x * 80 + 80, m->pl.player_y * 80);
		m->pl.player_x += 1;
		return (1);
	}
	return (0);
}

int	move_up(t_map *m)
{
	if ((m->data_map[m->pl.player_y - 1][m->pl.player_x] != '1'
		&& m->data_map[m->pl.player_y - 1][m->pl.player_x] != 'E')
			|| door_open(m,
			m->pl.player_y - 1, m->pl.player_x))
	{
		if (m->data_map[m->pl.player_y - 1][m->pl.player_x] == 'N')
			lose();
		if (m->data_map[m->pl.player_y - 1][m->pl.player_x] == 'C')
		{
			(--m->collectible);
			m->data_map[m->pl.player_y - 1][m->pl.player_x] = '0';
			mlx_put_image_to_window(m->vars.mlx, m->vars.win, m->img.img_gr,
				m->pl.player_x * 80, m->pl.player_y * 80 - 80);
		}
		mlx_put_image_to_window(m->vars.mlx, m->vars.win, m->img.img_gr,
			m->pl.player_x * 80, m->pl.player_y * 80);
		mlx_put_image_to_window(m->vars.mlx, m->vars.win, m->img.img_player,
			m->pl.player_x * 80, m->pl.player_y * 80 - 80);
		m->pl.player_y -= 1;
		return (1);
	}
	return (0);
}

int	door_open(t_map *m, int x, int y)
{
	if (m->collectible == 0 && m->data_map[x][y] == 'E')
		win();
	return (0);
}
