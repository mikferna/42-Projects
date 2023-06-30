/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:36:31 by mikferna          #+#    #+#             */
/*   Updated: 2023/06/30 13:27:23 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	checker(int argc, char **argv)
{
	char	**list;
	int		i;

	if (argc == 2)
	{
		list = ft_split(argv[1], ' ');
		i = 0;
		while (list[i])
			i++;
		if (!ft_check_elements(&argv[1], argc))
			ft_exit_2("Error");
		cheker_dups_arg(i, list);
		cheker_order_arg(i, list);
	}
	else if (argc > 2)
	{
		if (!ft_check_elements(&argv[1], argc))
			ft_exit_2("Error");
		cheker_comillas_arg(argc, argv);
		cheker_dups_arg(argc, argv);
		cheker_order_arg(argc, argv);
	}
}

void	cheker_comillas_arg(int argc, char **argv)
{
	int	i;
	int	l;

	i = 2;
	while (i <= argc - 1 && argv[i][0])
	{
		l = 0;
		while (argv[i][l])
		{
			if (argv[i][l] == ' ' || argv[i][l] == '	')
				ft_exit_2("Error en comillas");
			l++;
		}
		i++;
	}
}

int	*cheker_dups_arg(int argc, char **argv)
{
	int	i;
	int	*num_list;
	int	j;

	num_list = malloc(sizeof(int) * argc);
	if (num_list == NULL)
		ft_exit_2("Malloc Error 'num_list'\n");
	i = 0;
	while (++i < argc)
		num_list[i] = atoi(argv[i]);
	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (num_list[i] == num_list[j])
				ft_exit_2("Numeros Duplicados\n");
			j++;
		}
		i++;
	}
	return (num_list);
}

void	cheker_order_arg(int argc, char **argv)
{
	int	i;
	int	current_num;
	int	prev_num;

	i = 1;
	while (i < argc)
	{
		current_num = atoi(argv[i]);
		prev_num = atoi(argv[i - 1]);
		if (current_num < prev_num)
			return ;
		i++;
	}
	write(1, "Numeros Ordenados", 18);
	exit(0);
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
