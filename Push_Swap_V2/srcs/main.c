/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:10:10 by mikferna          #+#    #+#             */
/*   Updated: 2023/08/28 15:04:36 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	b = NULL;
	if (argc < 2)
	{
		write(1, "\n", 2);
		exit(0);
	}
	else
	{
		a = checker(argc, argv);
		//b = malloc(sizeof(t_list));
		algorithm(&a, &b);
	}
}
