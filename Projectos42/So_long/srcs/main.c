/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:27:50 by mikferna          #+#    #+#             */
/*   Updated: 2023/02/17 15:40:10 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int	open_wind(char *argv)
{
	t_main	programa;

	map_check(argv, &programa);
	programa.mlx = mlx_init();
	mlx_new_window(programa.mlx,
		programa.mapa->anch * 32, programa.mapa->alt * 32, "so_long");
	mlx_loop(programa.mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	args_check(argc, argv);
	open_wind(argv[1]);
	exit(2);
	return (0);
}
