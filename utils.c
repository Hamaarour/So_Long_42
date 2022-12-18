/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:05:21 by hamaarou          #+#    #+#             */
/*   Updated: 2022/12/18 12:54:49 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
int ft_error()
{
    printf("Error of reading the map");
    return (0);
}

int exit_game(void)
{
    exit(1);
    return (0);
}
int key_hook_press(int keycode, void *param)
{
    t_vars vars;
    t_img ii;
    void *img;

    static int count_move = 0;
    if (keycode == 13 || keycode == 126)
    {
        ft_printf("You presse buttun UP    move ==> [%d]\n", ++count_move);
    }
    else if (keycode == 0 || keycode == 123)
        ft_printf("You presse buttun LEFT  move ==> [%d]\n", ++count_move);
    else if (keycode == 1 || keycode == 125)
        ft_printf("You presse buttun DOWN  move ==> [%d]\n", ++count_move);
    else if (keycode == 2 || keycode == 124)
        ft_printf("You presse buttun RIGHT move ==> [%d]\n", ++count_move);
    else if (keycode == 53)
        exit(1);    
    return (0);
}
