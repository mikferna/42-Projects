/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:02:01 by mikferna          #+#    #+#             */
/*   Updated: 2023/02/14 14:33:42 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	args_check(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		write(1, "Cantidad de argumentos invalidos", 33);
		exit(2);
	}
	if (!termina_con_ber(argv[1]))
	{
		write(1, "Tipo de archivo no compatible", 30);
		exit(2);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
	{
		write(1, "Archivo Vacio", 14);
		exit(2);
	}
}
