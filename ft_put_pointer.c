/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohanegg <mohanegg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 20:37:32 by mohanegg          #+#    #+#             */
/*   Updated: 2026/11/14 22:58:49 by mohanegg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_pointer(void *ptr)
{
	unsigned long	caster;
	int				len;
	int				check_fail;

	if (!ptr)
	{
		check_fail = write(1, "(nil)", 5);
		if (check_fail != 5)
			return (-1);
		return (5);
	}
	len = 0;
	caster = (unsigned long)ptr;
	check_fail = ft_putstr("0x");
	if (check_fail != 2)
		return (-1);
	len += check_fail;
	check_fail = ft_put_hex(caster, 'x');
	if (check_fail == -1)
		return (-1);
	len += check_fail;
	return (len);
}
