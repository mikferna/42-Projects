/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:50:43 by mikferna          #+#    #+#             */
/*   Updated: 2023/08/23 13:50:35 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_list **list)
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
	write(1, "swap\n", 6);
}

void	rotate(t_list **list)
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
	write(1, "rotate\n", 8);
}

void	revrotate(t_list **list)
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
	write(1, "revrotate\n", 11);
}

void	push(t_list **list1, t_list **list2)
{
	t_list	*temp;

	if ((*list1))
	{
		temp = (*list1);
		(*list1) = (*list1)->next;
		temp->next = (*list2);
		(*list2) = temp;
	}
	write(1, "push\n", 6);
}
