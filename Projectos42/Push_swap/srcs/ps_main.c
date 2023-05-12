/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:25:21 by mikferna          #+#    #+#             */
/*   Updated: 2023/05/10 13:27:53 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_main	datos;

	if (argc <= 2)
	{
		printf("Hola");
		return (0);
	}
	else
	{
		checkers(argc, argv, &datos);
	}
}
