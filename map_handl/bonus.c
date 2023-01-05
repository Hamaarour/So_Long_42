/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:32:27 by hamaarou          #+#    #+#             */
/*   Updated: 2023/01/05 23:24:18 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	fill_arr_animation_enemy(t_map *m)
{
	m->enemy[0] = mlx_xpm_file_to_image(m->vars.mlx,
			"./Textures/enemy/e-1.xpm", &m->img.width, &m->img.height);
	m->enemy[1] = mlx_xpm_file_to_image(m->vars.mlx,
			"./Textures/enemy/e-2.xpm", &m->img.width, &m->img.height);
	m->enemy[2] = mlx_xpm_file_to_image(m->vars.mlx,
			"./Textures/enemy/e-3.xpm", &m->img.width, &m->img.height);
	m->enemy[3] = mlx_xpm_file_to_image(m->vars.mlx,
			"./Textures/enemy/e-4.xpm", &m->img.width, &m->img.height);
}

void	fill_arr_animation(t_map *m)
{
	m->ani[0] = mlx_xpm_file_to_image(m->vars.mlx, "./Textures/coins/1.xpm",
			&m->img.width, &m->img.height);
	m->ani[1] = mlx_xpm_file_to_image(m->vars.mlx, "./Textures/coins/2.xpm",
			&m->img.width, &m->img.height);
	m->ani[2] = mlx_xpm_file_to_image(m->vars.mlx, "./Textures/coins/3.xpm",
			&m->img.width, &m->img.height);
	m->ani[3] = mlx_xpm_file_to_image(m->vars.mlx, "./Textures/coins/4.xpm",
			&m->img.width, &m->img.height);
	m->ani[4] = mlx_xpm_file_to_image(m->vars.mlx, "./Textures/coins/5.xpm",
			&m->img.width, &m->img.height);
	m->ani[5] = mlx_xpm_file_to_image(m->vars.mlx, "./Textures/coins/6.xpm",
			&m->img.width, &m->img.height);
	m->ani[6] = mlx_xpm_file_to_image(m->vars.mlx, "./Textures/coins/7.xpm",
			&m->img.width, &m->img.height);
	m->ani[7] = mlx_xpm_file_to_image(m->vars.mlx, "./Textures/coins/8.xpm",
			&m->img.width, &m->img.height);
	m->ani[8] = mlx_xpm_file_to_image(m->vars.mlx, "./Textures/coins/9.xpm",
			&m->img.width, &m->img.height);
	m->ani[9] = mlx_xpm_file_to_image(m->vars.mlx, "./Textures/coins/10.xpm",
			&m->img.width, &m->img.height);
}

void	animation(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->data_map[y])
	{
		x = 0;
		while (map->data_map[y][x])
		{
			if (map->data_map[y][x] == 'C')
			{
				mlx_put_image_to_window(map->vars.mlx, map->vars.win,
					map->img.img_gr, x * 80, y * 80);
				mlx_put_image_to_window(map->vars.mlx, map->vars.win,
					map->ani[map->index], x * 80, y * 80);
			}
			x++;
		}
		y++;
	}
}

void	animation_enemy(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->data_map[y])
	{
		x = 0;
		while (map->data_map[y][x])
		{
			if (map->data_map[y][x] == 'N')
			{
				mlx_put_image_to_window(map->vars.mlx, map->vars.win,
					map->img.img_gr, x * 80, y * 80);
				mlx_put_image_to_window(map->vars.mlx, map->vars.win,
					map->enemy[map->index_enemy], x * 80, y * 80);
			}
			x++;
		}
		y++;
	}
}

int	animation_timer(t_map *map)
{
	if (map->timer > 1800)
	{
		map->timer = 0;
		animation(map);
		animation_enemy(map);
		map->index++;
		map->index_enemy++;
		if (map->index == 10)
			map->index = 0;
		if (map->index_enemy == 4)
			map->index_enemy = 0;
	}
	map->timer++;
	return (1);
}
