/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ent.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:57:39 by mikferna          #+#    #+#             */
/*   Updated: 2023/03/07 18:58:40 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	check_ent(char *argv, t_main *datos)
{
	int		fd;
	int		e;
	int		p;
	int		c;
	char	*line;

	e = 0;
	p = 0;
	c = 0;
	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		line = get_next_line(fd);
		e += ft_strrchr(line, 'E');
		p += ft_strrchr(line, 'P');
		c += ft_strrchr(line, 'C');
	}
	datos->param->c2 = c;
	ent_pas(e, p, c);
	close (fd);
}

void	ent_pas(int e, int p, int c)
{
	if (e != 1)
		ft_exit_2("Cantidad de salidas incorrecta");
	if (p != 1)
		ft_exit_2("Cantidad de jugadores incorectos");
	if (c < 1)
		ft_exit_2("Cantidad de monedas incorrectas");
}

int	ft_strrchr(const char *str, char c)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (str && str[i++])
	{
		if (str[i] == c)
			l++;
	}
	return (l);
}

void	check_path(char *argv, t_main	*datos)
{
	char	**copy;
	int		fd;
	int		i;
	int		l;

	i = 0;
	fd = open(argv, O_RDONLY);
	l = rectangular_map(argv);
	copy = (char **)malloc(sizeof(char *) * (l + 1));
	copydatos(datos, argv);
	while (1)
	{
		copy[i] = get_next_line(fd);
		if (copy[i] == NULL || i >= l - 1)
			break ;
		i++;
	}
	copy[i] = NULL;
	path_check2(copy, pfinder_x(copy), pfinder_y(copy));
	ent_check2(copy, 'e', 'P', 'C');
	close(fd);
	free(copy);
}

char	**path_check2(char **copy, int x, int y)
{
	if (copy[y][x] == 'P' || copy[y][x] == 'C'
		|| copy[y][x] == '0')
	{
		sust(copy, y, x);
		path_check2(copy, x, y - 1);
		if (copy[y][x] == 'P' || copy[y][x] == 'C'
			|| copy[y][x] == '0' || copy[y][x] == 'x')
		{
			sust(copy, y, x);
			path_check2(copy, x + 1, y);
			if (copy[y][x] == 'P' || copy[y][x] == 'C'
				|| copy[y][x] == '0' || copy[y][x] == 'x')
			{
				sust(copy, y, x);
				path_check2(copy, x, y + 1);
				if (copy[y][x] == 'P' || copy[y][x] == 'C' || copy[y][x] == '0'
					|| copy[y][x] == 'x')
				{
					sust(copy, y, x);
					path_check2(copy, x - 1, y);
				}
			}
		}
	}
	return (copy);
}
