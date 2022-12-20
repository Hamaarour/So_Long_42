/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:03:09 by hamaarou          #+#    #+#             */
/*   Updated: 2022/12/19 15:13:19 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void map(t_map *map)
{
    int fd;
    char **total;
    char *line;

    fd = open("./maps/map3.ber", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        line = ft_strjoin_v(line, line);
    }
    printf("%s", line);
}

void rad_map(t_img *img, t_vars *vars)
{
    int fd;
    char *str;
    int y = 0;
    int x;

    fd = open("./maps/map3.ber", O_RDONLY);
    while ((str = get_next_line(fd)) != NULL)
    {
        x = 0;
        while (str[x])
        {
            if (str[x] == '1')
                mlx_put_image_to_window(vars->mlx, vars->win, img->img_wall, x * 50, y * 50);
            else if (str[x] == '0')
                mlx_put_image_to_window(vars->mlx, vars->win, img->img_gr, x * 50, y * 50);
            else if (str[x] == 'C')
            {
                mlx_put_image_to_window(vars->mlx, vars->win, img->img_gr, x * 50, y * 50);
                mlx_put_image_to_window(vars->mlx, vars->win, img->img_collec, x * 50, y * 50);
            }
            else if (str[x] == 'P')
            {
                mlx_put_image_to_window(vars->mlx, vars->win, img->img_gr, x * 50, y * 50);
                mlx_put_image_to_window(vars->mlx, vars->win, img->img_player, x * 50, y * 50);
            }
            else if (str[x] == 'E')
            {
                mlx_put_image_to_window(vars->mlx, vars->win, img->img_gr, x * 50, y * 50);
                mlx_put_image_to_window(vars->mlx, vars->win, img->img_exit, x * 50, y * 50);
            }
            x++;
        }
        y++;
    }
}

int main(int argc, char **argv)
{
    void *img;
    t_img ii;
    t_vars vars;
    t_map m;

    if (argc != 2)
    {
        ft_error();
        return (0);
    }
    if (ft_check_map_path(argv[1]) == 0)
    {
        ft_error();
        return (0);
    }
    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 19 * 50, 8 * 50, "Splinter game");
    ii.img_wall = mlx_xpm_file_to_image(vars.mlx, "./images/wall.xpm", &ii.width, &ii.height);
    ii.img_collec = mlx_xpm_file_to_image(vars.mlx, "./images/collectible.xpm", &ii.width, &ii.height);
    ii.img_exit = mlx_xpm_file_to_image(vars.mlx, "./images/exit.xpm", &ii.width, &ii.height);
    ii.img_gr = mlx_xpm_file_to_image(vars.mlx, "./images/gr.xpm", &ii.width, &ii.height);
    ii.img_player = mlx_xpm_file_to_image(vars.mlx, "./images/player.xpm", &ii.width, &ii.height);
    map(&m);
    //rad_map(&ii, &vars);

    mlx_key_hook(vars.win, key_hook_press, (void *)0);
    mlx_hook(vars.win, 17, 0, exit_game, (void *)0);
    mlx_loop(vars.mlx);
}
