/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:03:09 by hamaarou          #+#    #+#             */
/*   Updated: 2022/12/18 16:45:51 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
 * Check the file path if containes
 *  ".ber" in the end
*/
int ft_check_map_path(char *map_path)
{
    int len;
    char *s;

    len = ft_strlen(map_path);
    s = &map_path[(len - 4)];
    printf("%s", s);
    if (ft_strncmp(s, ".ber", 4) == 0)
        return (1);
    return (0);
}

void    rad_map(t_img *img, t_vars *vars)
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
    vars.win = mlx_new_window(vars.mlx, 19*50, 8*50, "Splinter game");
    ii.img_wall= mlx_xpm_file_to_image(vars.mlx, "./images/wall.xpm", &ii.width, &ii.height);
    ii.img_collec = mlx_xpm_file_to_image(vars.mlx, "./images/collectible.xpm", &ii.width, &ii.height);
    ii.img_exit = mlx_xpm_file_to_image(vars.mlx, "./images/exit.xpm", &ii.width, &ii.height);
    ii.img_gr = mlx_xpm_file_to_image(vars.mlx, "./images/gr.xpm", &ii.width, &ii.height);
    ii.img_player = mlx_xpm_file_to_image(vars.mlx, "./images/player.xpm", &ii.width, &ii.height);

    rad_map(&ii,&vars);
 
    mlx_key_hook(vars.win, key_hook_press, (void *)0);
    mlx_hook(vars.win, 17, 0, exit_game, (void *)0);
    mlx_loop(vars.mlx);
}
