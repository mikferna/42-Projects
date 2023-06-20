/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:35:05 by mikferna          #+#    #+#             */
/*   Updated: 2023/06/15 11:04:46 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(char **argv, t_list *a)
{
	int		i;
	t_list	*temp;

	i = 0;
	while (argv[i])
	{
		temp->next->num = argv[i];
		temp->next->index = i;
		i++;
		printf("Num: [%i], Index: [%i]", temp->next->num, temp->next->index);
	}
	temp = temp->next;
}
