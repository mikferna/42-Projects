/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:53:24 by mikferna          #+#    #+#             */
/*   Updated: 2023/02/28 11:38:38 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	load_struct(t_main	*datos)
{
	datos->text.floor = mlx_xpm_file_to_image(datos->mlx,
			"sprites/floor.xpm", &datos->text.width, &datos->text.height);
	datos->text.player = mlx_xpm_file_to_image(datos->mlx,
			"sprites/player.xpm", &datos->text.width, &datos->text.height);
	datos->text.wall = mlx_xpm_file_to_image(datos->mlx,
			"sprites/wall.xpm", &datos->text.width, &datos->text.height);
	datos->text.collect = mlx_xpm_file_to_image(datos->mlx,
			"sprites/collect.xpm", &datos->text.width, &datos->text.height);
	datos->text.exit = mlx_xpm_file_to_image(datos->mlx,
			"sprites/exit.xpm", &datos->text.width, &datos->text.height);
}

void	load(t_main	*datos)
{
	load_struct(datos);
	make_map(datos);
}

void	make_map(t_main	*datos)
{
	int	l;
	int	i;

	l = 0;
	printf("datos->copy -> [%s]", datos->copy[3]);
	while (datos->copy[l])
	{
		i = 0;
		while (datos->copy[l][i])
		{
			mlx_put_image_to_window(datos->mlx, datos->window, datos->text.floor, i * 50, l * 50);
			if (datos->copy[l][i] == '1')
				mlx_put_image_to_window(datos->mlx, datos->window, datos->text.wall, i * 50, l * 50);
			if (datos->copy[l][i] == 'P')
				mlx_put_image_to_window(datos->mlx, datos->window, datos->text.player, i * 50, l * 50);
			if (datos->copy[l][i] == 'C')
				mlx_put_image_to_window(datos->mlx, datos->window, datos->text.collect, i * 50, l * 50);
			if (datos->copy[l][i] == 'E')
				mlx_put_image_to_window(datos->mlx, datos->window, datos->text.exit, i * 50, l * 50);
			i++;
		}
		l++;
	}
}
