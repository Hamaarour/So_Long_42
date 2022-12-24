/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 09:54:31 by hamaarou          #+#    #+#             */
/*   Updated: 2022/12/24 20:24:13 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	calcul_digit(int n)
{
	int		i;
	long	num;

	num = (long)n;
	i = 0;
	if (num == 0)
		i++;
	if (num < 0)
		i++;
	while (num != 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

static char	*fun(int n, char *ptr, int j, long l)
{
	while (n != 0)
	{
		ptr[j] = n % 10 + '0';
		n /= 10;
		j--;
	}
	ptr[calcul_digit(l)] = 0;
	return (ptr);
}

static char	*alloc_zero(char *ptr)
{
	ptr[0] = '0';
	ptr[1] = 0;
	return (ptr);
}

char	*ft_itoa(int l)
{
	char	*ptr;
	int		j;
	int		n;

	n = l;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	ptr = malloc(calcul_digit(n) + 1);
	if (!ptr)
		return (NULL);
	if (n == 0)
		return (alloc_zero(ptr));
	if (n < 0)
	{
		ptr[0] = '-';
		n *= -1;
	}
	if (l > 0)
		j = calcul_digit(n) - 1;
	else
		j = calcul_digit(n);
	ptr = fun(n, ptr, j, l);
	return (ptr);
}
