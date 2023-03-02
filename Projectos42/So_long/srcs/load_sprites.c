/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:53:24 by mikferna          #+#    #+#             */
/*   Updated: 2023/03/02 12:52:33 by mikferna         ###   ########.fr       */
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
	if (!datos->text.floor || !datos->text.player || !datos->text.wall ||
		!datos->text.collect || !datos->text.exit)
		ft_exit_2("Sprites mal cargados");
}

void	init(t_main	*datos)
{
	load_struct(datos);
	make_map(datos, 0, 0);
}

void	make_map(t_main	*datos, int l, int i)
{
	while (datos->copy[l])
	{
		i = 0;
		while (datos->copy[l][i])
		{
			mlx_put_image_to_window(datos->mlx, datos->window,
				datos->text.floor, i * 50, l * 50);
			if (datos->copy[l][i] == '1')
				mlx_put_image_to_window(datos->mlx, datos->window,
					datos->text.wall, i * 50, l * 50);
			if (datos->copy[l][i] == 'P')
				mlx_put_image_to_window(datos->mlx, datos->window,
					datos->text.player, i * 50, l * 50);
			if (datos->copy[l][i] == 'C')
				mlx_put_image_to_window(datos->mlx, datos->window,
					datos->text.collect, i * 50, l * 50);
			if (datos->copy[l][i] == 'E')
				mlx_put_image_to_window(datos->mlx, datos->window,
					datos->text.exit, i * 50, l * 50);
			i++;
		}
		l++;
	}
}

//#define KEY_W 13
//#define KEY_A 0
//#define KEY_S 1
//#define KEY_D 2

int	movements(int move, t_main *datos, int i, int l)
{
	static int	b;

	i = pfinder_x(datos->copy);
	l = pfinder_y(datos->copy);
	b += movecheck(move, datos, i, l);
	make_map(datos, 0, 0);
	esc_key_hook(move, datos);
	return (0);
}

int	movecheck(int move, t_main *datos, int i, int l)
{
	if (move == 0)
		if (datos->copy[l][i - 1] == 'C')
			datos->param->c += 1;
	if (move == 1)
		if (datos->copy[l + 1][i] == 'C')
			datos->param->c += 1;
	if (move == 2)
		if (datos->copy[l][i + 1] == 'C')
			datos->param->c += 1;
	if (move == 13)
		if (datos->copy[l - 1][i] == 'C')
			datos->param->c += 1;
	if (datos->param->c == datos->param->c2)
		win_move(move, datos, i, l);
	moves(move, datos, i, l);
	return (1);
}
