/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:10:10 by mikferna          #+#    #+#             */
/*   Updated: 2023/08/18 13:45:39 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;

	a = NULL;
	if (argc < 2)
	{
		printf("Lista No Existe");
		return (0);
	}
	else
	{
		checker(argc, argv, a);
	}
}
