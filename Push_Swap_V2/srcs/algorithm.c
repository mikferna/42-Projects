/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:52:05 by mikferna          #+#    #+#             */
/*   Updated: 2023/08/28 15:15:24 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algorithm(t_list **lst_a, t_list **lst_b)
{
	int	len;

	len = ft_lstsize(*lst_a);
	if (len == 2)
		swap(lst_a, 'a');
	else if (len == 3)
		three_nbr(lst_a, 'a');
	else if (len == 5)
		five_nbr(lst_a, lst_b);
	//else
	//	big_nbr(lst_a, lst_b);
}

void	three_nbr(t_list **list, char type)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = (*list);
	second = (*list)->next;
	third = second->next;
	if (first->num > second->num && first->num < third->num)
		swap(list, type);
	else if (first->num > second->num && second->num > third->num)
	{
		swap(list, type);
		revrotate(list, type);
	}
	else if (first->num > second->num && second->num < third->num)
		rotate(list, type);
	else if (first->num < second->num && second->num > third->num)
	{
		swap(list, type);
		rotate(list, type);
	}
	else if (first->num < second->num && second->num > third->num)
		revrotate(list, type);
}

void	five_nbr(t_list **list_a, t_list **list_b)
{
	int		i;
	int		max;
	int		min;
	t_list	*temp;

	i = ft_lstsize(*list_a);
	temp = NULL;
	while ((*list_a)->index <= i / 2)
		push(list_a, &temp, 'b');
	*list_b = temp;
	while (*list_b)
	{
		relmaxmin(*list_b);
		temp = *list_b;
		while (temp && temp != NULL)
		{
			if (temp->maxmin == 1)
				max = temp->relpos;
			if (temp->maxmin == -1)
				min = temp->relpos;
			temp = temp->next;
		}
		if (absolute(max) > absolute(min))
			make_move(list_a, list_b, min, -1);
		else
			make_move(list_a, list_b, max, 1);
	}
}
 