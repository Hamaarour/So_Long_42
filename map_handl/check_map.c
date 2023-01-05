/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:56:53 by hamaarou          #+#    #+#             */
/*   Updated: 2023/01/05 17:06:53 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
* *check if the map has  a new line
*/
int	check_newline(t_map *map)
{
	map->y = 0;
	while (map->lines[map->y])
	{
		if (map->lines[map->y] == '\n' && map->lines[map->y + 1] == '\n')
		{
			ft_printf("Map Error\n");
			exit (1);
		}
		map->y++;
	}
	return (1);
}

/*
* * check if the map has only  0 1 P E N C
*/

void	kk(t_map *map)
{
	while (map->data_map[++map->height])
	{
		map->width = -1;
		while (map->data_map[map->height][++map->width])
		{
			if (map->data_map[map->height][map->width] != '1'
			&& map->data_map[map->height][map->width] != '0'
			&& map->data_map[map->height][map->width] != 'P'
			&& map->data_map[map->height][map->width] != 'E'
			&& map->data_map[map->height][map->width] != 'C'
			&& map->data_map[map->height][map->width] != 'N')
				not_element();
		}
	}
}

/*
 * *read map ant return width and height
 * * of the map
*/
int	map(t_map *map, char *argv)
{
	char	**total;
	char	*line;

	map->lines = NULL;
	map->fd = open(argv, O_RDONLY);
	if (map->fd == -1)
		return (0);
	line = get_next_line(map->fd);
	while (line != NULL)
	{
		map->lines = ft_strjoin_split(map->lines, line);
		free(line);
		line = NULL;
		line = get_next_line(map->fd);
	}
	check_newline(map);
	total = ft_split(map->lines, '\n');
	map->height = -1;
	map->data_map = total;
	check_p(map, &(map->pl));
	kk(map);
	check_line_length(map);
	check_square(map);
	check_path(map);
	return (1);
}
