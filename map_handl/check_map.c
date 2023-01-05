/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:56:53 by hamaarou          #+#    #+#             */
/*   Updated: 2023/01/05 13:41:12 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
 * *read map ant return width and height
 * * of the map
*/
int	map(t_map *map, char *argv)
{
	char	**total;
	char	*line;

	map->y = 0;
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
	while (map->lines[map->y])
	{
		if (map->lines[map->y] == '\n' && map->lines[map->y + 1] == '\n')
			return (0);
		map->y++;
	}
	total = ft_split(map->lines, '\n');
	map->height = -1;
	map->data_map = total;
	//check_player_position(map);
	check_p(map, &(map->pl));
	while (total[++map->height])
	{
		map->width = -1;
		while (total[map->height][++map->width])
		{
			if (total[map->height][map->width] != '1' && total[map->height][map->width] != '0' && total[map->height][map->width] != 'P'
				&& total[map->height][map->width] != 'E' && total[map->height][map->width] != 'C'
				&& total[map->height][map->width] != 'N')
				return (0);
		}
	}
	check_line_length(map);
	check_square(map);
	//check_path(map);
	return (1);
}
