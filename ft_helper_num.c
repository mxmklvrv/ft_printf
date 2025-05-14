/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklevero <mklevero@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 19:00:05 by mklevero          #+#    #+#             */
/*   Updated: 2025/05/14 14:45:40 by mklevero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnum(int n) 
{
	int		i;
	int		print;
	long	dup;
	char	res;

	i = 0;
	dup = (long)n;
	if (dup < 0)
	{
		if (ft_putchar('-') < 0)
			return (-1);
		i++;
		dup = -dup;
	}
	if (dup >= 10)
	{
		print = ft_putnum(dup / 10);
		if (print < 0)
			return (-1);
		i+= print;
	}
	res = (dup % 10) + '0';
	if (ft_putchar(res) < 0)
		return (-1);
	i++;
	return (i);
}

int ft_putnum_unsigned(unsigned int n)
{
	int i;
	char res;

	i = 0;
	if (n >= 10)
		i+= ft_putnum_unsigned(n / 10);
	res = (n % 10) + '0';
	if (ft_putchar(res) < 0)
		return (-1);
	i++;
	return (i);
}


