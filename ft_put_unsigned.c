/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohanegg <mohanegg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 17:25:15 by mohanegg          #+#    #+#             */
/*   Updated: 2026/11/14 22:22:49 by mohanegg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_unsigned_recursive(unsigned int nb)
{
	char	d;
	int		count;
	int		check_fail;

	count = 0;
	if (nb > 9)
	{
		count = ft_unsigned_recursive(nb / 10);
		if (count == -1)
			return (-1);
		check_fail = ft_unsigned_recursive(nb % 10);
		if (check_fail == -1)
			return (-1);
		count += check_fail;
	}
	else
	{
		d = nb + '0';
		check_fail = ft_putchar(d);
		if (check_fail != 1)
			return (-1);
		count++;
	}
	return (count);
}

int	ft_put_unsigned(unsigned int nb)
{
	int	count;
	int	check_fail;

	count = 0;
	check_fail = ft_unsigned_recursive(nb);
	if (check_fail == -1)
		return (-1);
	count += check_fail;
	return (count);
}
