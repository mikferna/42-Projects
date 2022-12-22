/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:14:55 by mikferna          #+#    #+#             */
/*   Updated: 2022/11/22 15:24:34 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *str, ...)
{
	size_t		i;
	int			length;
	va_list		arg;

	if (!str)
		return (-1);
	i = 0;
	length = 0;
	va_start(arg, str);
	while (str[i] != 0)
	{
		if (str[i] == '%')
		{
			length += funciones(arg, str[i + 1]);
			i++;
		}
		else
			length += ft_putchar(str[i]);
		i++;
	}
	va_end(arg);
	return (length);
}
