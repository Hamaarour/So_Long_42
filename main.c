/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:03:09 by hamaarou          #+#    #+#             */
/*   Updated: 2023/01/05 13:19:03 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_map *p)
{
	p->img.img_wall = mlx_xpm_file_to_image(p->vars.mlx, "./Textures/wall.xpm",
			&p->img.width, &p->img.height);
	p->img.img_exit = mlx_xpm_file_to_image(p->vars.mlx, "./Textures/exit.xpm",
			&p->img.width, &p->img.height);
	p->img.img_gr = mlx_xpm_file_to_image(p->vars.mlx, "./Textures/gr.xpm",
			&p->img.width, &p->img.height);
	p->img.img_player = mlx_xpm_file_to_image(p->vars.mlx,
			"./Textures/player.xpm",
			&p->img.width,
			&p->img.height);
	fill_arr_animation(p);
	fill_arr_animation_enemy(p);
}

int	main(int argc, char **argv)
{
	t_map	m;

	m.timer = 0;
	m.index = 0;
	m.index_enemy = 0;
	if (argc != 2 || !ft_check_map_path(argv[1]) || !map(&m, argv[1]))
	{
		printf("Error of reading the map");
		exit(1);
	}
	m.vars.mlx = mlx_init();
	m.vars.win = mlx_new_window(m.vars.mlx, m.width * 80, m.height * 80,
			"Holo Game");
	mlx_hook(m.vars.win, 2, 0, key_hook_press, &m);
	put_image(&m);
	render_map(&m);
	mlx_loop_hook(m.vars.mlx, animation_timer, &m);
	mlx_hook(m.vars.win, 17, 0, ft_exit, 0);
	mlx_loop(m.vars.mlx);
}
