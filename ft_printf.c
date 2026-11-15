/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohanegg <mohanegg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 20:54:19 by mohanegg          #+#    #+#             */
/*   Updated: 2026/11/15 09:37:19 by mohanegg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_process_format(va_list args, const char *format,
		size_t *index)
{
	int	check_fail;

	(*index)++;
	if (format[*index] == '\0')
		return (ft_putchar('%'));
	check_fail = ft_handle_conversion(args, format[*index]);
	if (check_fail == -1)
		return (-1);
	(*index)++;
	return (check_fail);
}

static int	ft_process_char(const char *format, size_t *index)
{
	int	check_fail;

	check_fail = ft_putchar(format[*index]);
	if (check_fail == -1)
		return (-1);
	(*index)++;
	return (check_fail);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	index;
	int		count;
	int		check_fail;

	if (!format)
		return (-1);
	index = 0;
	count = 0;
	va_start(args, format);
	while (format[index])
	{
		if (format[index] == '%')
			check_fail = ft_process_format(args, format, &index);
		else
			check_fail = ft_process_char(format, &index);
		if (check_fail == -1)
		{
			va_end(args);
			return (-1);
		}
		count += check_fail;
	}
	va_end(args);
	return (count);
}
