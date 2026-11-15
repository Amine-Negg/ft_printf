/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohanegg <mohanegg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 20:52:18 by mohanegg          #+#    #+#             */
/*   Updated: 2026/11/15 09:42:42 by mohanegg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_text(va_list args, char specifier)
{
	char	*str;

	if (specifier == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (specifier == 's')
	{
		str = va_arg(args, char *);
		if (!str)
			str = "(null)";
		return (ft_putstr(str));
	}
	return (ft_putchar('%'));
}

static int	ft_handle_number(va_list args, char specifier)
{
	int				number;
	unsigned int	unsigneed;

	if (specifier == 'd' || specifier == 'i')
	{
		number = va_arg(args, int);
		return (ft_putnbr(number));
	}
	unsigneed = va_arg(args, unsigned int);
	return (ft_put_unsigned(unsigneed));
}

static int	ft_handle_hex(va_list args, char specifier)
{
	unsigned int	un;
	void			*ptr;

	if (specifier == 'x' || specifier == 'X')
	{
		un = va_arg(args, unsigned int);
		return (ft_put_hex(un, specifier));
	}
	ptr = va_arg(args, void *);
	return (ft_put_pointer(ptr));
}

static int	ft_put_unknown(char specifier)
{
	int	check_fail;
	int	count;

	count = ft_putchar('%');
	if (count == -1)
		return (-1);
	check_fail = ft_putchar(specifier);
	if (check_fail == -1)
		return (-1);
	return (count + check_fail);
}

int	ft_handle_conversion(va_list args, char specifier)
{
	if (specifier == 'c' || specifier == 's' || specifier == '%')
		return (ft_handle_text(args, specifier));
	if (specifier == 'd' || specifier == 'i' || specifier == 'u')
		return (ft_handle_number(args, specifier));
	if (specifier == 'x' || specifier == 'X' || specifier == 'p')
		return (ft_handle_hex(args, specifier));
	return (ft_put_unknown(specifier));
}
