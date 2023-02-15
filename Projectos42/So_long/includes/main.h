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

typedef	struct s_posicion
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

int		main(int argc, char **argv);
int		open_wind(char *argv);
void	args_check(int argc, char **argv);
int		termina_con_ber(const char *cadena);
int		map_check (char *ber);
int		empty_line_map(int fd);
int		rectangular_map(int fd);

#endif