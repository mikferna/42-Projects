/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:20:03 by mikferna          #+#    #+#             */
/*   Updated: 2023/08/07 13:51:29 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init(int *list)
{
	t_list	*a;
	t_list	**head;
	t_list	*b;

	a = malloc(sizeof(t_list));
	if (a == NULL)
		return (0);
	b = malloc(sizeof(t_list));
	if (b == NULL)
		return (0);
	head = &a;
	
}
