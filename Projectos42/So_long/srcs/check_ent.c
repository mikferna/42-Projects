/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ent.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:57:39 by mikferna          #+#    #+#             */
/*   Updated: 2023/02/23 13:39:41 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	check_ent(char *argv)
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
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		e += ft_strrchr(line, 'E');
		p += ft_strrchr(line, 'P');
		c += ft_strrchr(line, 'C');
	}
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

int	ft_strrchr(char *str, char c)
{
	int	i;
	int	l;

	l = 0;
	i = ft_strlen2(str);
	while (str[i--] > 0)
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

	i = 0;
	fd = open(argv, O_RDONLY);
	copy = (char **)malloc(sizeof(char *) * (datos->mapa->alt + 1));
	while (1)
	{
		copy[i] = get_next_line(fd);
		if (copy[i] == NULL)
			break ;
		i++;
	}
	copy = path_check2(copy, pfinder_x(copy), pfinder_y(copy));
	hola (copy);
	ent_check2(copy, 'E', 'P', 'C');
	close(fd);
	free(copy);
}

char	**path_check2(char **copy, int x, int y)
{
	if (copy[y][x] == '0' || copy[y][x] == 'E'
		|| copy[y][x] == 'C' || copy[y][x] == 'P')
	{
		copy[y][x] = 'o';
		path_check2(copy, x, y - 1);
		if (copy[y][x] == 'o')
		{
			copy[y][x] = 'o';
			path_check2(copy, x + 1, y);
		}
	}
	if (copy[y][x] == 'o')
	{
		copy[y][x] = 'o';
		path_check2(copy, x - 1, y);
	}
	if (copy[y][x] == 'o')
	{
		copy[y][x] = 'o';
		path_check2(copy, x, y + 1);
	}
	return (copy);
}
