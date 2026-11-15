/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohanegg <mohanegg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 17:55:16 by mohanegg          #+#    #+#             */
/*   Updated: 2026/11/14 22:25:19 by mohanegg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hex(unsigned long n, char format)
{
	char	*base;
	int		len;
	int		check_fail;

	len = 0;
	if (format == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
	{
		check_fail = ft_put_hex(n / 16, format);
		if (check_fail == -1)
			return (-1);
		len += check_fail;
	}
	check_fail = ft_putchar(base[n % 16]);
	if (check_fail != 1)
		return (-1);
	len += check_fail;
	return (len);
}
