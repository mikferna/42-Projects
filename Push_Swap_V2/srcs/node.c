/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:53:07 by mikferna          #+#    #+#             */
/*   Updated: 2023/08/18 11:56:12 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/push_swap.h"

void	addback(t_list	*list, int value, int id)
{
	t_list	*c;

	while (list->next != NULL)
		list = list->next;
	c = malloc(sizeof(t_list));
	c->num = value;
	c->index = id;
	c->next = NULL;

	list->next = c;
}

t_list	*ft_lstnew(int num, int id)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->num = num;
	new->index = id;
	new->next = NULL;
	return (new);
}
