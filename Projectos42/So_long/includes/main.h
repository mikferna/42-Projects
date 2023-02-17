/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:18:26 by mikferna          #+#    #+#             */
/*   Updated: 2023/02/17 13:23:41 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

#include "../srcs/gnl/get_next_line.h"
#include "../minilibx/mlx.h"

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_posicion
{
	int	x;
	int	y;
}	t_posicion;

typedef struct s_mapa
{
	char	**archivo;
	int		alt;
	int		anch;
}	t_mapa;

typedef struct s_param
{
	int		p;
	int		e;
	int		c;
}	t_param;

typedef struct s_main
{
	void	*mlx;
	t_mapa	*mapa;
}	t_main;

int		main(int argc, char **argv);
int		open_wind(char *argv);
void	args_check(int argc, char **argv);
int		termina_con_ber(const char *cadena);
void	map_check(char *argv, t_main	*programa);
size_t	ft_strlen2(const char *s);
int		check_walls(char *argv, int linecount);
int		check_walls_full(char *linea);
void	check_walls_middle(char *linea);
int		rectangular_map(char *argv);
void	ft_exit_2(char *str);

#endif