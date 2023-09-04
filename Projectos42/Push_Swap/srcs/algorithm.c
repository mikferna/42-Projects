/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:52:05 by mikferna          #+#    #+#             */
/*   Updated: 2023/09/04 15:24:37 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algorithm(t_list **lst_a, t_list **lst_b)
{
	int	len;

	lst_a = indexor(lst_a);
	len = ft_lstsize(*lst_a);
	if (len == 2)
		swap(lst_a, 'a');
	else if (len == 3)
		three_nbr(lst_a, 'a');
	else if (len > 3 && len <= 5)
		five_nbr(lst_a, lst_b);
	else if (len > 5 && len <= 100)
		mid_nbr(lst_a, lst_b);
	else
		big_nbr(lst_a, lst_b);
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
	else if (first->num < second->num && second->num > third->num
		&& first->num < third->num)
	{
		swap(list, type);
		rotate(list, type);
	}
	else if (first->num < second->num && second->num > third->num
		&& first->num > third->num)
		revrotate(list, type);
}

void	mid_nbr(t_list **list_a, t_list **list_b)
{
	int		i;
	int		l;

	i = ft_lstsize(*list_a);
	l = 0;
	*list_b = NULL;
	append(list_a, list_b, l, i);
	while ((*list_a)->index != 0)
		rotate(list_a, 'a');
}

void	append(t_list **list_a, t_list **list_b, int l, int i)
{
	while (l < i / 2)
	{
		if ((*list_a)->index < i / 2)
		{
			push(list_a, list_b, 'b');
			l++;
		}
		else
			rotate(list_a, 'a');
	}
	moves(list_a, list_b, 0, 0);
	while (l < i)
	{
		if ((*list_a)->index >= i / 2)
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
}

void	moves(t_list **list_a, t_list**list_b, int min, int max)
{
	t_list	*temp;

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
		if (absolute(max) > absolute(min + 1))
			make_move(list_a, list_b, min);
		else
			make_move(list_a, list_b, max);
	}
}
