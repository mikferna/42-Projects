/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublemovements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:29:00 by mikferna          #+#    #+#             */
/*   Updated: 2023/08/23 13:55:41 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	doubleswap(t_list **list1, t_list **list2)
{
	swap(list1);
	swap(list2);
	write(1, "ss\n", 3);
}

void	doublerotate(t_list **list1, t_list **list2)
{
	rotate(list1);
	rotate(list2);
	write(1, "rr\n", 3);
}

void	doublerevrotate(t_list **list1, t_list **list2)
{
	revrotate(list1);
	revrotate(list2);
	write(1, "rrr\n", 4);
}
