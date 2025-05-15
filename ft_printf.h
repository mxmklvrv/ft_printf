/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklevero <mklevero@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:55:39 by mklevero          #+#    #+#             */
/*   Updated: 2025/05/15 12:27:26 by mklevero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define BASE16U "0123456789ABCDEF"
# define BASE16L "0123456789abcdef"

int	ft_printf(const char *format, ...);
int	ft_putchar(int c);
int	ft_putstr(const char *str);
int	ft_putnum(long n);
int	ft_putnum_unsigned(unsigned int n);
int	ft_base(unsigned long n, unsigned long base, char *str);
int	ft_ptr(void *ptr);
int	check_format(const char *format, va_list *args);

#endif