/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:19:19 by mikferna          #+#    #+#             */
/*   Updated: 2023/06/30 13:38:05 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_check_elements(char **argv, int argc)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[j])
	{
		if (!ft_check_maxint(&argv[j]))
			return (0);
		if (argv[j][i] == '-')
			i++;
		while (argv[j][i])
		{
			if (ft_isdigit(argv[j][i], argc) == 0)
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

int	ft_isdigit(int c, int argc)
{
	if (((c >= '0' && c <= '9') || c == ' '
			|| c == '-' || c == '+') && argc == 2)
		return (1);
	else if ((c >= '0' && c <= '9') || c == '-' || c == '+')
		return (1);
	return (0);
}

int	ft_check_maxint(char **argv)
{
	if (ft_long_atoi(*argv) > 2147483647)
		return (0);
	if (ft_long_atoi(*argv) < -2147483648)
		return (0);
	return (1);
}

long int	ft_long_atoi(const char *str)
{
	size_t		i;
	long int	num;
	int			sign;

	i = 0;
	num = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}
