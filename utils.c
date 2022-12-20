/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:05:21 by hamaarou          #+#    #+#             */
/*   Updated: 2022/12/20 23:44:48 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_map_path(char *map_path)
{
	int		len;
	char	*s;

	len = ft_strlen(map_path);
	s = &map_path[(len - 4)];
	if (ft_strncmp(s, ".ber", 4) == 0)
		return (1);
	return (0);
}

int	ft_error(void)
{
	printf("Error of reading the map");
	exit(1);
	return (0);
}

int	key_hook_press(int keycode, void *param)
{
	t_vars		vars;
	t_img		ii;
	void		*img;
	static int	count_move;

	count_move = 0;
	if (keycode == 13 || keycode == 126)
	{
		ft_printf("You pressed button UP    move ==> [%d]\n", ++count_move);
	}
	else if (keycode == 0 || keycode == 123)
		ft_printf("You pressed button  LEFT  move ==> [%d]\n", ++count_move);
	else if (keycode == 1 || keycode == 125)
		ft_printf("You pressed button  DOWN  move ==> [%d]\n", ++count_move);
	else if (keycode == 2 || keycode == 124)
		ft_printf("You pressed button  RIGHT move ==> [%d]\n", ++count_move);
	else if (keycode == 53)
		exit(1);
	return (0);
}

int	map(t_map *map)
{
	int		fd;
	char	**total;
	char	*line;
	char	*lines;
	int		y;
	int x;

	fd = open("./maps/map3.ber", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
		lines = ft_strjoin_split(lines, line);
	total = ft_split(lines, '\n');
	y = 0;
	while (total[y])
	{
		x = 0;
		while (total[y][x])
		{
			
			if (total[y][x] != '1' || total[y][x] != '0' 
				|| total[y][x] != 'E' || total[y][x] != 'C' || total[y][x] != 'P')
			{
				printf("y > %c\n", total[y][x]);
				return (0);
				}
				
			
			x++;
		}
		y++;
	}
	map->data_map = total;

	return (1);
}

int	check_line_length(t_map *map)
{
	int	y;
	int	k;
	int	x;

	y = 1;
	k = ft_strlen(map->data_map[0]);
	while (map->data_map[y])
	{
		x = 0;
		if (k != ft_strlen(map->data_map[y]))
			return (0);
		y++;
	}
	return (1);
}

void	check_player_position(t_map *map)
{
	int	y;
	int	x;
	int	len_hight;
	int	len_width;
	int	k;

	y = 0;
	while (map->data_map[y])
	{
		x = 0;
		while (map->data_map[y][x])
		{
			if (map->data_map[y][x] == 'P')
			{
				map->player_x = x;
				map->player_y = y;
			}
			x++;
		}
		y++;
	}
	return ;
}
