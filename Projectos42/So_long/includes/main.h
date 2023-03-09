/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:18:26 by mikferna          #+#    #+#             */
/*   Updated: 2023/03/09 11:25:58 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

#include "../srcs/gnl/get_next_line.h"
#include "../srcs/libft/libft.h"
#include "../minilibx/mlx.h"

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdbool.h>

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
	int		c2;
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

/*-main.c-*/
int		main(int argc, char **argv);
int		open_wind(char *argv);

/*-mapa.c-*/
void	map_check(char *argv, t_main *datos);
int		check_walls(char *argv, int linecount);
int		check_walls_full(char *linea);
void	check_walls_middle(char *linea);
int		rectangular_map(char *argv);

/*-load_sprites.c-*/
void	load_struct(t_main *datos);
void	init(t_main	*datos);
void	make_map(t_main	*datos, int l, int i);
int		movements(int move, t_main *datos, int i, int l);
int		movecheck(int move, t_main *datos, int i, int l);

/*-funciones.c-*/
int		termina_con_ber(const char *cadena);
size_t	ft_strlen2(const char *s);
int		moves(int move, t_main *datos, int i, int l);
void	sust(char **copy, int y, int x);

/*-check_ent2-*/
void	ent_check2(char **copy, char e, char f, char r);
int		pfinder_x(char **copy);
int		pfinder_y(char **copy);
void	copydatos(t_main *datos, char *argv);
int		handle_destroy(t_main *datos);

/*-check_ent-*/
void	check_ent(char *argv, t_main *datos);
void	ent_pas(int e, int p, int c);
int		ft_strrchr(const char *str, char c);
void	check_path(char *argv, t_main	*datos);
char	**path_check2(char **copy, int x, int y);

/*-check_command-*/
void	args_check(int argc, char **argv);
void	ft_exit_2(char *str);
int		esc_key_hook(int esc, t_main *datos);
void	win_move(int move, t_main *datos, int i, int l);
void	ft_exit_0(char *str);


#endif 