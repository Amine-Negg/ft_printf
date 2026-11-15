/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohanegg <mohanegg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 14:53:06 by mohanegg          #+#    #+#             */
/*   Updated: 2026/11/14 22:57:06 by mohanegg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;
	int	check_fail;

	if (!str)
	{
		check_fail = write(1, "(null)", 6);
		if (check_fail == -1)
			return (-1);
		return (6);
	}
	i = 0;
	while (str[i])
	{
		check_fail = write(1, &str[i], 1);
		if (check_fail != 1)
			return (-1);
		i++;
	}
	return (i);
}
