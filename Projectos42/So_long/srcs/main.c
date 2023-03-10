/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:27:50 by mikferna          #+#    #+#             */
/*   Updated: 2023/03/09 10:42:13 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int	open_wind(char *argv)
{
	t_main	datos;

	map_check(argv, &datos);
	datos.mlx = mlx_init();
	datos.window = mlx_new_window(datos.mlx,
			datos.mapa->anch * 50, datos.mapa->alt * 50, "so_long");
	init(&datos);
	mlx_hook(datos.window, 17, 0, &handle_destroy, &datos);
	mlx_hook(datos.window, 2, 0, &movements, &datos);
	mlx_loop(datos.mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	args_check(argc, argv);
	open_wind(argv[1]);
	return (0);
}
