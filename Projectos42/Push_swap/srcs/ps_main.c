/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:25:21 by mikferna          #+#    #+#             */
/*   Updated: 2023/06/28 11:13:37 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	//t_list	a;
	//int		*argb;

	if (argc < 2)
	{
		printf("Lista Ordenada");
		return (0);
	}
	else
	{
		checker(argc, argv);
		//init(argb, &a);
	}
}
