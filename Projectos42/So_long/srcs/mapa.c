/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:26:32 by mikferna          #+#    #+#             */
/*   Updated: 2023/02/23 12:32:29 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	map_check(char *argv, t_main	*datos)
{
	int		linecount;
	int		rowcount;

	linecount = rectangular_map(argv);
	rowcount = check_walls(argv, linecount);
	check_ent(argv);
	check_path(argv, datos);
	datos->mapa->alt = linecount - 1;
	datos->mapa->anch = rowcount - 1;
}

int	check_walls(char *argv, int linecount)
{
	int	fd;
	int	rowcount;

	fd = open(argv, O_RDONLY);
	rowcount = check_walls_full(get_next_line(fd));
	while (linecount-- > 3)
		check_walls_middle(get_next_line(fd));
	check_walls_full(get_next_line(fd));
	return (rowcount);
}

int	check_walls_full(char *linea)
{
	int	i;

	i = 0;
	while (linea && linea[i])
	{
		if (linea[i] != '1' && linea[i] != '\n')
			ft_exit_2("Mapa incorrecto, esta mal cerrado");
		i++;
	}
	return (i);
}

void	check_walls_middle(char *linea)
{
	int	i;
	int	b;

	i = 0;
	b = ft_strlen2(linea) - 1;
	while (linea && linea[i])
	{
		if (linea[0] != '1' || linea[b] != '1')
			ft_exit_2("Mapa incorrecto, esta mal cerrado");
		if (linea[i] != '1' && linea[i] != 'P' && linea[i] != 'C'
			&& linea[i] != 'E' && linea[i] != '0' && linea[i] != '\n')
			ft_exit_2("Mapa incorrecto, caracteres erroneos");
		i++;
	}
}

int	rectangular_map(char *argv)
{
	int	a;
	int	b;
	int	fd;
	int	linecount;

	fd = open(argv, O_RDONLY);
	a = ft_strlen2(get_next_line(fd));
	b = ft_strlen2(get_next_line(fd));
	linecount = 2;
	while (b != 0)
	{
		if (a != b)
			ft_exit_2("Mapa incorrecto, no es rectangular");
		b = ft_strlen2(get_next_line(fd));
		linecount++;
	}
	close(fd);
	return (linecount);
}
