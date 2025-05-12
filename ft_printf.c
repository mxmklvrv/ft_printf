/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklevero <mklevero@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:25:04 by mklevero          #+#    #+#             */
/*   Updated: 2025/05/12 20:23:43 by mklevero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_printf(const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd')
				printf("%d", va_arg(args, int));
			else if (*format == 's')
				printf("%s", va_arg(args, char *));
		}
		else
			putchar(*format);
		format++;
	}
	va_end(args);
}
int	main(void)
{
	ft_printf("hello %s, numm of  %d\n", "gene", 42);
	printf(" mama4ka");
}