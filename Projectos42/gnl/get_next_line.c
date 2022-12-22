/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:32:35 by mikferna          #+#    #+#             */
/*   Updated: 2022/12/22 14:47:38 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*devolver_linea(int fd)
{
	static char	*buff;
	char	*linea;
	int		cont;
	int		cont2;

	cont = 0;
	cont2 = 0;
	buff = malloc(sizeof(char ) * BUFFER_SIZE + 1);
	linea = malloc(sizeof(char ) * BUFFER_SIZE + 1);
	read(fd, buff, BUFFER_SIZE);
	buff[BUFFER_SIZE] = '\0';
	while (buff[cont] && buff[cont] != '\n')
	{
		linea[cont2] = buff[cont];
		cont++;
		cont2++;
		if (!buff[cont])
		{
			read(fd, buff, BUFFER_SIZE);
			cont = 0;
		}
	}
	linea[cont2] = '\n';
	linea[cont2 + 1] = '\0';
	return (linea);
}

int	main(void)
{
	int	a;

	a = open("text.txt", O_RDONLY);
	printf("%s", get_next_line(a));
}
