/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:27:57 by hamaarou          #+#    #+#             */
/*   Updated: 2022/12/20 14:50:44 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int count_nbr(unsigned long nbr, int bs, int sign)
{
    int count;

    count = 0;
    if (nbr == 0)
        return (1);
    while (nbr != 0)
    {
        nbr /= bs;
        count++;
    }
    if (sign == -1)
        count++;
    return (count);
}
int ft_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}
int ft_putnbr_hex(unsigned long nbr, char bs)
{
    if (nbr >= 16)
    {
        ft_putnbr_hex((nbr / 16), bs);
        ft_putnbr_hex((nbr % 16), bs);
    }
    else
    {
        if (nbr < 10)
            ft_putnbr(nbr);
        else
            ft_putchar(nbr - 10 + 'a' + bs - 'x');
    }
    return (count_nbr(nbr, 16, 1));
}
int ft_putnbr(long int nbr)
{
    int a;

    a = 1;
    if (nbr < 0)
    {
        a = -1;
        ft_putchar('-');
        nbr *= -1;
    }
    if (nbr >= 10)
    {
        ft_putnbr(nbr / 10);
        ft_putnbr(nbr % 10);
    }
    else
        ft_putchar(nbr + 48);
    return (count_nbr(nbr, 10, a));
}
int ft_putstr(char *str)
{
    int i;
    char *n;

    n = "(null)";
    i = 0;
    if (!str)
        return (ft_putstr(n));
    while (str[i])
        write(1, &str[i++], 1);
    return (ft_strlen(str));
}