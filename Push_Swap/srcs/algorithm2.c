/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:21:22 by mikferna          #+#    #+#             */
/*   Updated: 2023/09/01 14:47:10 by mikferna         ###   ########.fr       */
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

void	big_nbr(t_list **list_a, t_list **list_b)
{
	int		i;
	int		l;

	i = ft_lstsize(*list_a);
	l = 0;
	*list_b = NULL;
	l = append_big_1(list_a, list_b, i, l);
	while ((*list_a)->index != 0)
		rotate(list_a, 'a');
	moves(list_a, list_b, 0, 0);
	append_big_2(list_a, list_b, i, l);
	while ((*list_a)->index != 0)
		rotate(list_a, 'a');
	moves(list_a, list_b, 0, 0);
	while ((*list_a)->index != 0)
		rotate(list_a, 'a');
}

int	append_big_1(t_list **list_a, t_list **list_b, int i, int l)
{
	while (l < i / 4)
	{
		if ((*list_a)->index < i / 4)
		{
			push(list_a, list_b, 'b');
			l++;
		}
		else
			rotate(list_a, 'a');
	}
	moves(list_a, list_b, 0, 0);
	while (l <= (i / 2))
	{
		if ((*list_a)->index >= i / 4 && (*list_a)->index <= i / 2)
		{
			push(list_a, list_b, 'b');
			l++;
		}
		else
			rotate(list_a, 'a');
	}
	return (l);
}

void	append_big_2(t_list **list_a, t_list **list_b, int i, int l)
{
	while (l <= (i / 2) + (i / 4))
	{
		if ((*list_a)->index > i / 2 && (*list_a)->index <= (i / 2) + (i / 4))
		{
			push(list_a, list_b, 'b');
			l++;
		}
		else
			rotate(list_a, 'a');
	}
	while ((*list_a)->index != 0)
		rotate(list_a, 'a');
	moves(list_a, list_b, 0, 0);
	while (l < i)
	{
		if ((*list_a)->index > (i / 2) + (i / 4) && (*list_a)->index <= i)
		{
			push(list_a, list_b, 'b');
			l++;
		}
		else
			rotate(list_a, 'a');
	}
}
