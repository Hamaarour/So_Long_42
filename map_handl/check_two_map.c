/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_two_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:54:33 by hamaarou          #+#    #+#             */
/*   Updated: 2023/01/05 13:41:37 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

/***
 * * check if the map surrounded by 1's
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
	{
		ft_printf("ERROR\nDuplicate");
		exit(1);
	}
	while (map->data_map[i])
	{
		if (i == 0 || i == map->height - 1)
		{
			j = 0;
			while (map->data_map[i][j])
			{
				if (map->data_map[i][j] != '1')
				{
					ft_printf("ERROR\nthe map not surrounded by 1's");
					exit(1);
				}
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
	int		y;
	size_t	k;
	int		x;

	y = 1;
	k = ft_strlen(map->data_map[0]);
	while (map->data_map[y])
	{
		x = 0;
		if (k != ft_strlen(map->data_map[y]))
		{
			ft_printf("ERROR\nLenght");
			exit(1);
		}
		y++;
	}
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
