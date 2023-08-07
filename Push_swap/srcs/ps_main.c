/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:25:21 by mikferna          #+#    #+#             */
/*   Updated: 2023/08/07 13:35:10 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	int	*list;

	if (argc < 2)
	{
		printf("Lista No Existe");
		return (0);
	}
	else
	{
		list = checker(argc, argv);
		if (list == NULL)
			ft_exit_2("Error2");
		init(list);
	}
}
