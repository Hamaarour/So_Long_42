/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_v.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:31:03 by hamaarou          #+#    #+#             */
/*   Updated: 2022/12/20 14:36:20 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char *ft_strjoin_split(char *s1, char *s2)
{
	char *p;
	int i;
	int j;
	int full_len;

	i = 0;
	j = 0;
	if(!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	full_len = ft_strlen(s1) + ft_strlen(s2);
	p = malloc(full_len + 1);
	if (!p)
		return (NULL);
	while (s1[i])
	{
		p[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
		p[j++] = s2[i++];
	p[j] = 0;
	return (p);
}
