/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklevero <mklevero@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:25:04 by mklevero          #+#    #+#             */
/*   Updated: 2025/05/13 13:16:47 by mklevero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>


int check_format(char ch, va_list args)
{
	// to check the char and send it to corresponding function
}



int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	total;
	int count;

	if (!format)
		return (-1);
	total = 0; 
	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%') // what if afther '%' there is \0 ?? 
		{
			format++;
			count= check_format(*format, &args);
		}
		else
			count = write(1, format, 1);
		if (count == -1)
			return(va_end(args), -1);
		total+= count;
		format++;
	}
	return(va_end(args), total);
}


