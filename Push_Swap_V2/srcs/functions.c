/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:50:19 by mikferna          #+#    #+#             */
/*   Updated: 2023/08/28 15:05:59 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_exit_2(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	exit (2);
}

void	atoi_check(char *num)
{
	if (ft_atoil(num) > MAX_INT)
		ft_exit_2("Int Invalido");
	if (ft_atoil(num) < MIN_INT)
		ft_exit_2("Int Invalido");
}

void	relative_calc(t_list *list)
{
	t_list	*temp;
	int		i;
	int		val;

	i = 0;
	val = ft_lstsize(list);
	temp = list;
	while (i < val / 2)
	{
		temp->relpos = i;
		temp = temp->next;
		i++;
	}
	while (i < val)
	{
		temp->relpos = (i - val);
		temp = temp->next;
		i++;
	}
}

void	findmaxmin(t_list *list)
{
	int		max;
	int		min;
	t_list	*tmp;

	max = list->num;
	printf("list->num = [%d]\n", list->num);
	min = list->num;
	tmp = list;
	while (list->next)
	{
		//printf("list->num = [%i]\n", list->num);
		if (list->num > max)
			max = list->num;
		if (list->num < min)
			min = list->num;
		//printf("max = [%i]\n", max);
		//printf("min = [%i]\n", min);
		list = list->next;
	}
	while (tmp)
	{
		if (tmp->num == max)
			tmp->maxmin = 1;
		else if (tmp->num == min)
			tmp->maxmin = -1;
		else
			tmp->maxmin = 0;
		tmp = tmp->next;
	}
}

void	relmaxmin(t_list *list)
{
	findmaxmin(list);
	relative_calc(list);
}
