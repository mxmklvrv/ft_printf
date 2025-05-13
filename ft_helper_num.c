/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklevero <mklevero@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 19:00:05 by mklevero          #+#    #+#             */
/*   Updated: 2025/05/13 20:09:12 by mklevero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnum(int n)
{
	int		i;
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
		i += ft_putnum(dup / 10);
	res = (dup % 10) + '0';
	if (ft_putchar(res) < 0)
		return (-1);
	i++;
	return (i);
}
