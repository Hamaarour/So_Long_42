/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:03:09 by hamaarou          #+#    #+#             */
/*   Updated: 2022/12/22 23:16:00 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_img *ii, t_vars *vars)
{
	ii->img_wall = mlx_xpm_file_to_image(vars->mlx, "./Textures/wall.xpm",
			&ii->width, &ii->height);
	ii->img_collect = mlx_xpm_file_to_image(vars->mlx,
			"./Textures/collectible.xpm", &ii->width, &ii->height);
	ii->img_exit = mlx_xpm_file_to_image(vars->mlx, "./Textures/exit.xpm",
			&ii->width, &ii->height);
	ii->img_gr = mlx_xpm_file_to_image(vars->mlx, "./Textures/gr.xpm",
			&ii->width, &ii->height);
	ii->img_player = mlx_xpm_file_to_image(vars->mlx, "./Textures/player.xpm",
			&ii->width, &ii->height);
}

int	main(int argc, char **argv)
{
	t_img	ii;
	t_vars	vars;
	t_map	m;

	if (argc != 2 || !ft_check_map_path(argv[1]) || !map(&m, argv[1]))
	{
		printf("Error of reading the map");
		return (0);
	}
	if (!check_line_length(&m) || !check_square(&m))
	{
		printf("Error of reading the map");
		return (0);
	}
	check_player_position(&m);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, m.width * 50, m.height * 50,
			"Splinter game");
	put_image(&ii, &vars);
	render_map(&ii, &vars, argv[1], &m);
	mlx_key_hook(vars.win, key_hook_press, 0);
	mlx_hook(vars.win, 17, 0, ft_exit, 0);
	mlx_loop(vars.mlx);
	mlx_destroy_window(vars.mlx, vars.win);
}
