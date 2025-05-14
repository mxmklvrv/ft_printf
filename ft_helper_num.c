/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklevero <mklevero@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 19:00:05 by mklevero          #+#    #+#             */
/*   Updated: 2025/05/14 18:59:24 by mklevero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnum(long n)
{
	int		i;
	int		check;
	char	res;

	i = 0;
	if (n < 0)
	{
		if (ft_putchar('-') < 0)
			return (-1);
		i++;
		n = -n;
	}
	if (n >= 10)
	{
		check = ft_putnum(n / 10);
		if (check < 0)
			return (-1);
		i += check;
	}
	res = (n % 10) + '0';
	if (write(1, &res, 1) < 0)
		return (-1);
	i++;
	return (i);
}

int	ft_putnum_unsigned(unsigned int n)
{
	int		i;
	int		check;
	char	res;

	i = 0;
	if (n >= 10)
	{
		check = ft_putnum_unsigned(n / 10);
		if (check < 0)
			return (-1);
		i += check;
	}
	res = (n % 10) + '0';
	if (write(1, &res, 1) < 0)
		return (-1);
	i++;
	return (i);
}

int	ft_base(unsigned long n, unsigned long base, char *str)
{
	int	i;
	int	check;
	int	index;

	i = 0;
	if (n > base - 1)
	{
		check = ft_base(n / base, base, str);
		if (check < 0)
			return (-1);
		i += check;
	}
	index = n % base;
	if (write(1, &str[index], 1) < 0)
		return (-1);
	i++;
	return (i);
}

int	ft_ptr(void *ptr)
{
	int	ox;
	int	address;

	if (!ptr)
		return (ft_putstr("(nil)"));
	ox = write(1, "0x", 2);
	address = ft_base((unsigned long)ptr, 16, BASE16L);
	if (ox == -1 || address == -1)
		return (-1);
	return (ox + address);
}
