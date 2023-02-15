/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:27:50 by mikferna          #+#    #+#             */
/*   Updated: 2023/02/15 13:39:25 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int	open_wind(char *argv)
{
	t_mapa mapa;
	void	*mlx;

	map_check(argv);
	mlx = mlx_init();
	mlx_new_window(mlx, mapa.alt * 50, mapa.anch * 50, "so_long");
	mlx_loop(mlx);
	(void)argv;
	return (0);
}

int	main(int argc, char **argv)
{
	args_check(argc, argv);
	open_wind(argv[1]);
	exit(2);
	return (0);
}
