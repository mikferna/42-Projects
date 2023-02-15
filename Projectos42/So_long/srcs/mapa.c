/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:26:32 by mikferna          #+#    #+#             */
/*   Updated: 2023/02/15 14:08:36 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int	map_check (char *ber)
{
	int fd;

	fd = open(ber, O_RDONLY);
	//empty_line_map(fd);
	rectangular_map(fd);
	return (0);
	
}

//int	empty_line_map(int fd)
//{
//	while(get_next_line(fd))
//	{
//		if (get_next_line(fd) == '\n')
//			{
//				write(1, "Mapa incorrecto, linea vacia", 29);
//				exit(2);
//			}
//	}
//	return (0);
//}

int	rectangular_map(int fd)
{
	int	a;
	int	b;

	while(get_next_line(fd))
	{
		a = ft_strlen(get_next_line(fd));
		b = ft_strlen(get_next_line(fd));
		if (a != b)
		{
			write(1, "Mapa incorrecto, no es rectangular", 35);
			exit(2);
		}
	}
	return (0);
}