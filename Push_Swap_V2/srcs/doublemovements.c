/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublemovements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:29:00 by mikferna          #+#    #+#             */
/*   Updated: 2023/08/29 14:55:41 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	doubleswap(t_list **list1, t_list **list2)
{
	swap(list1, 'x');
	swap(list2, 'x');
	write(1, "ss\n", 3);
}

void	doublerotate(t_list **list1, t_list **list2)
{
	rotate(list1, 'x');
	rotate(list2, 'x');
	write(1, "rr\n", 3);
}

void	doublerevrotate(t_list **list1, t_list **list2)
{
	revrotate(list1, 'x');
	revrotate(list2, 'x');
	write(1, "rrr\n", 4);
}

t_list	**indexor(t_list **a)
{
	t_list	*aux1;
	t_list	*aux2;
	int		flag;

	aux1 = *a;
	flag = 0;
	while (aux1 && !flag)
	{
		aux2 = aux1->next;
		while (aux2 && !flag)
		{
			if (aux1->num > aux2->num)
				aux1->index += 1;
			else if (aux1->num == aux2->num)
				flag = 1;
			else
				aux2->index += 1;
			aux2 = aux2->next;
		}
		aux1 = aux1->next;
	}
	if (flag)
		return (NULL);
	return (a);
}
