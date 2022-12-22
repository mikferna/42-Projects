/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_priint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:37:47 by mikferna          #+#    #+#             */
/*   Updated: 2022/11/21 13:49:31 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_int(int n)
{
	size_t	length;

	length = 0;
	if (n == -2147483648)
	{
		length += ft_putstr("-2147483648");
		return (length);
	}
	if (n < 0)
	{
		length += ft_putchar('-');
		n = n * -1;
	}
	if (n >= 10)
	{
		length += ft_print_int(n / 10);
		length += ft_print_int(n % 10);
	}
	else
		length += ft_putchar(n + '0');
	return (length);
}
