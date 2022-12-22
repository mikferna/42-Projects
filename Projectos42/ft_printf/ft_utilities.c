/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:06:51 by mikferna          #+#    #+#             */
/*   Updated: 2022/11/21 14:14:44 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	funciones(va_list arg, char c)
{
	size_t	x;

	x = 0;
	if (c == '%')
		x += ft_putchar('%');
	else if (c == 'c')
		x += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		x += ft_putstr(va_arg(arg, char *));
	else if (c == 'd' || c == 'i')
		x += ft_print_int(va_arg(arg, int));
	else if (c == 'x')
		x += ft_printf_hex(va_arg(arg, unsigned int));
	else if (c == 'X')
		x += ft_printf_hex_maj(va_arg(arg, unsigned int));
	else if (c == 'p')
		x += ft_putstr("0x") + ft_putp(va_arg(arg, size_t));
	else if (c == 'u')
		x += ft_putu(va_arg(arg, unsigned int));
	return (x);
}

size_t	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_putstr(char *str)
{
	size_t	i;

	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	i = 0;
	while (str[i] != 0)
		write(1, &str[i++], 1);
	return (i);
}
