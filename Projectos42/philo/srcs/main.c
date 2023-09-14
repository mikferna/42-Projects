/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:06:18 by mikferna          #+#    #+#             */
/*   Updated: 2023/09/14 12:41:17 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_rules		rules;

	(void)argv;
	if (argc != 5 && argc != 6)
		ft_exit_2("Cantidad de argumentos incorrecta");
	if (init(&rules, argv))
		ft_exit_2("Rule Error");
	philo(&rules);
	//printf("Llego al final del main\n");
	return (0);
}
