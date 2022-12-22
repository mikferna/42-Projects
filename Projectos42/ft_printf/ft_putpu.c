/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:12:43 by mikferna          #+#    #+#             */
/*   Updated: 2022/11/24 12:03:05 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putp(unsigned long long n)
{
	size_t	i;

	i = 0;
	if (n > 15)
		i += ft_putp(n / 16);
	i += ft_putchar(HEXA[n % 16]);
	return (i);
}

size_t	ft_putu(unsigned int n)
{
	size_t	i;

	i = 0;
	if (n > 9)
	{
		i += ft_putu(n / 10);
		i += ft_putu(n % 10);
	}
	else
		i += ft_putchar(n + '0');
	return (i);
}
