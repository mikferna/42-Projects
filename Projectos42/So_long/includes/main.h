/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:18:26 by mikferna          #+#    #+#             */
/*   Updated: 2023/02/28 11:34:57 by mikferna         ###   ########.fr       */
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

typedef struct s_texturas {
	void	*player;
	void	*floor;
	void	*wall;
	void	*collect;
	void	*exit;
	int		width;
	int		height;
}	t_texturas;

typedef struct s_mapa
{
	char		**archivo;
	int			alt;
	int			anch;
}	t_mapa;

typedef struct s_param
{
	int		p;
	int		e;
	int		c;
}	t_param;

typedef struct s_main
{
	void		*mlx;
	void		*window;
	char		**copy;
	t_mapa		*mapa;
	t_texturas	text;
	t_param		*param;
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
void	check_ent(char *argv);
int		ft_strrchr(char *str, char c);
void	ent_pas(int e, int p, int c);
void	check_path(char *argv, t_main	*datos);
char	**path_check2(char **copy, int x, int y);
void	ent_check2(char **copy, char c, char f, char r);
void	pfinder(char **copy, t_main	*datos);
int		pfinder_x(char **copy);
int		pfinder_y(char **copy);
int		esc_key_hook(int esc, t_main *datos);
int		movements(int move, t_main *datos);
void	load(t_main	*datos);
void	load_struct(t_main *datos);
void	make_map(t_main	*datos);
void	copydatos(t_main *datos, char *argv);

#endif