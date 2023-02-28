/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ent2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:18:04 by mikferna          #+#    #+#             */
/*   Updated: 2023/02/28 11:35:24 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	ent_check2(char **copy, char c, char f, char r)
{
	int	i;
	int	l;

	l = 0;
	while (copy[l])
	{
		i = 0;
		while (copy[l][i])
		{
			if (copy[l][i] == c)
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

	fd = open(argv, O_RDONLY);
	i = 0;
	datos->copy = (char **)malloc(sizeof(char *) * (datos->mapa->alt + 1));
		while (1)
	{
		datos->copy[i] = get_next_line(fd);
		if (datos->copy[i] == NULL)
			break ;
		i++;
	}
}
	