/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:33:03 by hamaarou          #+#    #+#             */
/*   Updated: 2022/12/22 21:31:15 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	prnt_second(va_list args, char k)
{
	int	c;

	c = 0;
	if (k == 'c')
		c += ft_putchar(va_arg(args, int));
	if (k == 's')
		c += ft_putstr(va_arg(args, char *));
	if (k == 'd' || k == 'i')
		c += ft_putnbr(va_arg(args, int));
	if (k == 'u')
		c += ft_putnbr(va_arg(args, unsigned int));
	if (k == 'x')
		c += ft_putnbr_hex(va_arg(args, unsigned int), 'x');
	if (k == 'X')
		c += ft_putnbr_hex(va_arg(args, unsigned int), 'X');
	if (k == '%')
		c += ft_putchar('%');
	if (k == 'p')
	{
		c += ft_putstr("0x");
		c += ft_putnbr_hex(va_arg(args, unsigned long), 'x');
	}
	return (c);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!str)
		return (0);
	va_start(args, str);
	while (str[i] != 0)
	{
		if (str[i] == '%')
		{
			k += prnt_second(args, str[i + 1]);
			i++;
		}
		else
		{
			k += ft_putchar(str[i]);
		}
		i++;
	}
	va_end(args);
	return (k);
}
