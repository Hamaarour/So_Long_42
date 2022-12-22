/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:03:09 by hamaarou          #+#    #+#             */
/*   Updated: 2022/12/22 20:21:59 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	void	*img;
	t_img	ii;
	t_vars	vars;
	t_map	m;


	if (argc != 2)
	{
		ft_error();
		return (0);
	}
	if (!ft_check_map_path(argv[1]) || !map(&m, argv[1]))
	{
		ft_error();
		return (0);
	}
	if (!check_line_length(&m) || !check_square(&m))
		ft_error();
	check_player_position(&m);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, m.width * 50, m.height * 50,
			"Splinter game");
	ii.img_wall = mlx_xpm_file_to_image(vars.mlx, "./Textures/wall.xpm",
			&ii.width, &ii.height);
	ii.img_collect = mlx_xpm_file_to_image(vars.mlx,
											"./Textures/collectible.xpm",
											&ii.width,
											&ii.height);
	ii.img_exit = mlx_xpm_file_to_image(vars.mlx, "./Textures/exit.xpm",
			&ii.width, &ii.height);
	ii.img_gr = mlx_xpm_file_to_image(vars.mlx, "./Textures/gr.xpm", &ii.width,
			&ii.height);
	ii.img_player = mlx_xpm_file_to_image(vars.mlx, "./Textures/player.xpm",
			&ii.width, &ii.height);
	render_map(&ii, &vars, argv[1]);
	mlx_key_hook(vars.win, key_hook_press, 0);
	mlx_hook(vars.win, 17, 0, ft_error, 0);
	mlx_loop(vars.mlx);
	mlx_destroy_window(vars.mlx, vars.win);
	
}
