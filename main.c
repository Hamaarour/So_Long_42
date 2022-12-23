/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:03:09 by hamaarou          #+#    #+#             */
/*   Updated: 2022/12/24 00:27:26 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_map *p)
{
	p->img.img_wall = mlx_xpm_file_to_image(p->vars.mlx, "./Textures/wall.xpm",
			&p->img.width, &p->img.height);
	p->img.img_collect = mlx_xpm_file_to_image(p->vars.mlx,
												"./Textures/collectible.xpm",
												&p->img.width,
												&p->img.height);
	p->img.img_exit = mlx_xpm_file_to_image(p->vars.mlx, "./Textures/exit.xpm",
			&p->img.width, &p->img.height);
	p->img.img_gr = mlx_xpm_file_to_image(p->vars.mlx, "./Textures/gr.xpm",
			&p->img.width, &p->img.height);
	p->img.img_player = mlx_xpm_file_to_image(p->vars.mlx,
												"./Textures/player.xpm",
												&p->img.width,
												&p->img.height);
}

int	main(int argc, char **argv)
{
	//t_vars	vars;
	t_map	m;

	if (argc != 2 || !ft_check_map_path(argv[1]) || !map(&m, argv[1]))
	{
		printf("Error of reading the map");
		exit(1);
	}
	if (!check_line_length(&m) || !check_square(&m))
	{
		printf("Error of reading the map");
		exit(1);
	}
	check_player_position(&m);
	//printf(" x == %d .  y == %d", m.player_x, m. player_y);
	m.vars.mlx = mlx_init();
	m.vars.win = mlx_new_window(m.vars.mlx, m.width * 80, m.height * 80,
			"Splinter game");
	mlx_key_hook(m.vars.win, key_hook_press, &m);
	put_image(&m);
	render_map(&m);
	mlx_hook(m.vars.win, 17, 0, ft_exit, 0);
	mlx_loop(m.vars.mlx);
	mlx_destroy_window(m.vars.mlx, m.vars.win);
}
