/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:50:43 by mikferna          #+#    #+#             */
/*   Updated: 2023/08/29 16:55:24 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_list **list, char type)
{
	t_list	*temp;
	t_list	*temp2;

	if ((*list) && (*list)->next)
	{
		temp = (*list);
		temp2 = (*list)->next;
		temp->next = temp2->next;
		temp2->next = temp;
		(*list) = temp2;
	}
	if (type == 'a')
		write(1, "sa\n", 4);
	if (type == 'b')
		write(1, "sb\n", 4);
}

void	rotate(t_list **list, char type)
{
	t_list	*temp;
	t_list	*temp2;

	if ((*list) && (*list)->next)
	{
		temp = (*list);
		temp2 = (*list)->next;
		while (temp->next)
			temp = temp->next;
		temp->next = (*list);
		(*list)->next = NULL;
		(*list) = temp2;
	}
	if (type == 'a')
		write(1, "ra\n", 4);
	if (type == 'b')
		write(1, "rb\n", 4);
}

void	revrotate(t_list **list, char type)
{
	t_list	*temp;
	t_list	*temp2;

	if ((*list) && (*list)->next)
	{
		temp = (*list);
		while (temp->next->next)
			temp = temp->next;
		temp2 = temp->next;
		temp->next = NULL;
		temp2->next = (*list);
		(*list) = temp2;
	}
	if (type == 'a')
		write(1, "rra\n", 5);
	if (type == 'b')
		write(1, "rrb\n", 5);
}

void	push(t_list **list1, t_list **list2, char type)
{
	t_list	*temp;

	if (*list1)
	{
		temp = *list2;
		*list2 = *list1;
		*list1 = (*list1)->next;
		(*list2)->next = temp;
		(*list2)->maxmin = 0;
		(*list2)->relpos = 0;
	}
	if (type == 'a')
		write(1, "pa\n", 4);
	if (type == 'b')
		write(1, "pb\n", 4);
}

void	make_move(t_list **a, t_list **b, int rel)
{
	if (*b && ft_lstsize(*b) > 1)
	{
		while (rel < 0)
		{
			revrotate(b, 'b');
			rel++;
		}
		while (rel > 0)
		{
			rotate(b, 'b');
			rel--;
		}
	}
	if ((*b)->maxmin == -1)
	{
		push(b, a, 'a');
		rotate(a, 'a');
	}
	else
		push(b, a, 'a');
}
