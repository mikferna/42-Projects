/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:50:19 by mikferna          #+#    #+#             */
/*   Updated: 2023/08/21 16:50:38 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_exit_2(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	exit (2);
}

void	atoi_check(char *num)
{
	if (ft_atoil(num) > MAX_INT)
		ft_exit_2("Int Invalido");
	if (ft_atoil(num) < MIN_INT)
		ft_exit_2("Int Invalido");
}
