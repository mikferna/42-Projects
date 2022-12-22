/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:27:34 by mikferna          #+#    #+#             */
/*   Updated: 2022/11/15 14:52:21 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include <string.h>

# define HEXA "0123456789abcdef"
# define HEXA_M "0123456789ABCDEF"

size_t	funciones(va_list arg, char c);
size_t	ft_print_int(int n);
size_t	ft_len_hex(unsigned int n);
size_t	ft_printf_hex(unsigned int n);
size_t	ft_printf_hex_maj(unsigned int n);
int		ft_putp(unsigned long long n);
size_t	ft_putchar(char c);
size_t	ft_putstr(char *str);
size_t	ft_putu(unsigned int n);
int		ft_printf(char const *str, ...);

#endif
