/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohanegg <mohanegg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 14:58:27 by mohanegg          #+#    #+#             */
/*   Updated: 2026/11/14 23:16:36 by mohanegg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_recursive(int nb)
{
	char	d;
	int		count;
	int		check_fail;

	count = 0;
	if (nb > 9)
	{
		count = ft_putnbr_recursive(nb / 10);
		if (count == -1)
			return (-1);
		check_fail = ft_putnbr_recursive(nb % 10);
		if (check_fail == -1)
			return (-1);
		count += check_fail;
	}
	else
	{
		d = nb + '0';
		if (ft_putchar(d) == -1)
			return (-1);
		count++;
	}
	return (count);
}

int	ft_putnbr(int nb)
{
	int	count;
	int	check_fail;

	count = 0;
	if (nb == -2147483648)
	{
		check_fail = write(1, "-2147483648", 11);
		if (check_fail != 11)
			return (-1);
		return (11);
	}
	if (nb < 0)
	{
		check_fail = ft_putchar('-');
		if (check_fail == -1)
			return (-1);
		count = 1;
		nb = -nb;
	}
	check_fail = ft_putnbr_recursive(nb);
	if (check_fail == -1)
		return (-1);
	count += check_fail;
	return (count);
}
