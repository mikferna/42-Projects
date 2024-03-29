/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 12:48:10 by mikferna          #+#    #+#             */
/*   Updated: 2023/09/04 13:32:48 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_split(char **input)
{
	int	i;
	int	len;

	len = 0;
	while (input[len])
	{
		len++;
	}
	i = 0;
	while (i < len)
	{
		free (input[i]);
		i++;
	}
}

void	free_list(t_list *stack)
{
	t_list	*temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free (temp);
	}
}
