/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ent2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:18:04 by mikferna          #+#    #+#             */
/*   Updated: 2023/03/09 10:53:25 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	ent_check2(char **copy, char e, char f, char r)
{
	int	i;
	int	l;

	l = 0;
	while (copy[l])
	{
		i = 0;
		while (copy[l][i])
		{
			if (copy[l][i] == e)
				ft_exit_2("Imposible Map");
			if (copy[l][i] == f)
				ft_exit_2("Imposible Map");
			if (copy[l][i] == r)
				ft_exit_2("Imposible Map");
			i++;
		}
		l++;
	}
}

int	pfinder_x(char **copy)
{
	int	i;
	int	l;
	int	x;

	l = 0;
	while (copy[l])
	{
		i = 0;
		while (copy[l][i])
		{
			if (copy[l][i] == 'P')
			{
				x = i;
			}
			i++;
		}
		l++;
	}
	return (x);
}

int	pfinder_y(char **copy)
{
	int	i;
	int	l;
	int	y;

	l = 0;
	while (copy[l])
	{
		i = 0;
		while (copy[l][i])
		{
			if (copy[l][i] == 'P')
			{
				y = l;
			}
			i++;
		}
		l++;
	}
	return (y);
}

void	copydatos(t_main *datos, char *argv)
{
	int	fd;
	int	i;
	int	l;

	fd = open(argv, O_RDONLY);
	i = 0;
	l = rectangular_map(argv);
	datos->copy = (char **)malloc(sizeof(char *) * (l + 1));
	while (1)
	{
		datos->copy[i] = get_next_line(fd);
		if (datos->copy[i] == NULL || i >= l - 1)
			break ;
		i++;
	}
	datos->copy[i] = NULL;
}

int	handle_destroy(t_main *datos)
{
	mlx_destroy_window(datos->mlx, datos->window);
	exit(0);
	return (0);
}
