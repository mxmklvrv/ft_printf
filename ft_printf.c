/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklevero <mklevero@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:25:04 by mklevero          #+#    #+#             */
/*   Updated: 2025/05/13 20:16:46 by mklevero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int	check_format(const char *format, va_list *args)
{
	if (*format == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (*format == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (*format == '%')
		return (ft_putchar('%'));
	else if (*format == 'd' || *format == 'i')
		;
	return (ft_putnum(va_arg(*args, int)));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total;
	int		count;

	if (!format)
		return (-1);
	total = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count = check_format(format, &args);
		}
		else
			count = write(1, format, 1);
		if (count == -1)
			return (va_end(args), -1);
		total += count;
		format++;
	}
	return (va_end(args), total);
}
