/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:52:05 by mikferna          #+#    #+#             */
/*   Updated: 2023/08/23 14:44:30 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algorithm(t_list **lst_a, t_list **lst_b)
{
	int	len;

	(void)lst_b;
	len = ft_lstsize(*lst_a);
	if (len == 2)
		swap(lst_a);
	else if (len == 3)
		three_nbr(lst_a);
	else if (len == 5)
		five_nbr(lst_a, lst_b);
	//else
	//	big_nbr(lst_a, lst_b);
}

void	three_nbr(t_list **list)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = (*list);
	second = (*list)->next;
	third = second->next;
	if (first->num > second->num && first->num < third->num)
		swap(list);
	else if (first->num > second->num && second->num > third->num)
	{
		swap(list);
		revrotate(list);
	}
	else if (first->num > second->num && second->num < third->num)
		rotate(list);
	else if (first->num < second->num && second->num > third->num)
	{
		swap(list);
		rotate(list);
	}
	else if (first->num < second->num && second->num > third->num)
		revrotate(list);
}

void	five_nbr(t_list **list_a, t_list **list_b)
{
	push(list_a, list_b);
	push(list_a, list_b);
	three_nbr(list_a);
}
