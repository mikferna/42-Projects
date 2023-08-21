/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:10:10 by mikferna          #+#    #+#             */
/*   Updated: 2023/08/21 14:55:42 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	a;

	if (argc < 2)
	{
		write(1, "\n", 2);
		exit(0);
	}
	else
	{
		checker(argc, argv, &a);
	}
}
