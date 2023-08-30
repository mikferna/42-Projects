/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:21:22 by mikferna          #+#    #+#             */
/*   Updated: 2023/08/30 12:52:25 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	five_nbr(t_list **list_a, t_list **list_b)
{
	int	len;
	int	i;
	int	num;

	len = ft_lstsize(*list_a);
	i = 0;
	num = 0;
	while (i < len - 3)
	{
		if ((*list_a)->index < 2 && (*list_a)->index == num)
		{
			push(list_a, list_b, 'b');
			i++;
			num++;
		}
		else
			rotate(list_a, 'a');
	}
	three_nbr(list_a, 'a');
	moves(list_a, list_b, 0, 0);
	while ((*list_a)->index != 0)
		rotate(list_a, 'a');
}
