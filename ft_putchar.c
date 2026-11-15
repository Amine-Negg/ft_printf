/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohanegg <mohanegg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 14:56:13 by mohanegg          #+#    #+#             */
/*   Updated: 2026/11/14 21:25:24 by mohanegg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	char	ch;
	int		check_fail;

	ch = c;
	check_fail = write(1, &ch, 1);
	if (check_fail == -1)
		return (-1);
	return (check_fail);
}
