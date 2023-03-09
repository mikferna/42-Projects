/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funciones.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:49:29 by mikferna          #+#    #+#             */
/*   Updated: 2023/03/07 19:12:34 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int	termina_con_ber(const char *cadena)
{
	int			longitud_cadena;
	const char	*subcadena = ".ber";
	int			longitud_subcadena;
	const char	*puntero_cadena = cadena;

	longitud_subcadena = 4;
	longitud_cadena = 0;
	while (*puntero_cadena != '\0')
	{
		longitud_cadena++;
		puntero_cadena++;
	}
	if (longitud_cadena < longitud_subcadena)
		return (0);
	puntero_cadena = cadena + longitud_cadena - longitud_subcadena;
	while (*puntero_cadena == *subcadena)
	{
		if (*puntero_cadena == '\0')
			return (1);
		puntero_cadena++;
		subcadena++;
	}
	return (0);
}

size_t	ft_strlen2(const char *s)
{
	size_t	counter;

	counter = 0;
	if (!s)
		return (0);
	while (s[counter] && s[counter] != '\n')
		counter++;
	return (counter);
}

int	moves(int move, t_main *datos, int i, int l)
{
	if (move == 0 && datos->copy[l][i - 1] != '1' &&
		datos->copy[l][i - 1] != 'E')
	{
		datos->copy[l][i] = '0';
		datos->copy[l][i - 1] = 'P';
	}
	if (move == 1 && datos->copy[l + 1][i] != '1' &&
		datos->copy[l + 1][i] != 'E')
	{
		datos->copy[l][i] = '0';
		datos->copy[l + 1][i] = 'P';
	}
	if (move == 2 && datos->copy[l][i + 1] != '1' &&
		datos->copy[l][i + 1] != 'E')
	{
		datos->copy[l][i] = '0';
		datos->copy[l][i + 1] = 'P';
	}
	if (move == 13 && datos->copy[l - 1][i] != '1' &&
		datos->copy[l - 1][i] != 'E')
	{
		datos->copy[l][i] = '0';
		datos->copy[l - 1][i] = 'P';
	}
	return (0);
}

void	sust(char **copy, int y, int x)
{
	if (copy[y][x] == 'E')
		copy[y][x] = 'e';
	else
		copy[y][x] = 'x';
}
