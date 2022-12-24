/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:56:53 by hamaarou          #+#    #+#             */
/*   Updated: 2022/12/24 18:34:19 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
 * *read map ant return width and height
 * * of the map
*/
int	map(t_map *map, char *argv)
{
	int		fd;
	char	**total;
	char	*line;
	char	*lines;
	int		y;
	int		x;

	y = 0;
	lines = NULL;
	fd = open(argv, O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		lines = ft_strjoin_split(lines, line);
		free(line);
		line = NULL;
	}
	close(fd);
	while (lines[y])
	{
		if (lines[y] == '\n' && lines[y + 1] == '\n')
			return (0);
		y++;
	}
	total = ft_split(lines, '\n');
	free(lines);
	lines = NULL;
	y = 0;
	while (total[y])
	{
		x = 0;
		while (total[y][x])
		{
			if (total[y][x] != '1' && total[y][x] != '0' && total[y][x] != 'P'
				&& total[y][x] != 'E' && total[y][x] != 'C')
				return (0);
			x++;
		}
		y++;
	}
	map->width = x;
	map->height = y;
	map->data_map = total;
	return (1);
}

/***
 * * check if the map serenaded by 1's
 * * 11111111
 * * 1......1
 * * 1......1
 * * 11111111
*/
int	check_square(t_map *map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	if (!check_one_p_e_c(map))
		return (0);
	while (map->data_map[i])
	{
		if (i == 0 || i == map->height - 1)
		{
			j = 0;
			while (map->data_map[i][j])
			{
				if (map->data_map[i][j] != '1')
					return (0);
				j++;
			}
		}
		len = ft_strlen(map->data_map[0]);
		if (map->data_map[i][0] != '1' || map->data_map[i][len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

/*
 * * check if the map lines has
 * * the same length
*/
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

/*
 * * check if the has a minimum one player
 * * and 1 exit and at lest one collectible
 * * (pec)==> p = player , e = exit , c = collectible
*/
int	check_one_p_e_c(t_map *map)
{
	int	i;
	int	j;
	int	counter;
	int	count_collectible;

	i = 0;
	counter = 0;
	count_collectible = 0;
	while (map->data_map[i])
	{
		j = 0;
		while (map->data_map[i][j])
		{
			if (map->data_map[i][j] == 'P' || map->data_map[i][j] == 'E')
				counter++;
			if (map->data_map[i][j] == 'C')
				count_collectible++;
			j++;
		}
		i++;
	}
	map->collectible = count_collectible;
	if (count_collectible < 1 || counter > 2)
		return (0);
	return (1);
}

/**
 * *Check the path of the map
 * *need some features like (.ber.ber)
 */
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
