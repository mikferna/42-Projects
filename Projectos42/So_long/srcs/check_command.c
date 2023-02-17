/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:02:01 by mikferna          #+#    #+#             */
/*   Updated: 2023/02/17 11:53:28 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	args_check(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		ft_exit_2("Cantidad de argumentos invalidos");
	if (!termina_con_ber(argv[1]))
		ft_exit_2("Tipo de archivo no compatible");
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
		ft_exit_2("Archivo Vacio");
}

void	ft_exit_2(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	exit (2);
}
