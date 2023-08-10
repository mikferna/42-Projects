/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:32:32 by mikferna          #+#    #+#             */
/*   Updated: 2023/08/10 15:17:55 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	checker(int argc, char **argv)
{
	int	*num_list;
	int	cont;

	checker_characters(argc, argv);
	cont = lista(argc, argv);
	if (argc == 2)
		num_list = malloc(sizeof(int) * cont);
	else
		num_list = malloc(sizeof(int) * (argc - 1));
	if (num_list == NULL)
		ft_exit_2("Error Malloc");
	num_list = list_gen(argc, cont, argv);
	//free(num_list);
}

void	checker_characters(int argc, char **argv)
{
	int	i;
	int	l;

	i = 0;
	l = 1;
	while (argv && argv[l])
	{
		while (argv[l][i])
		{
			if ((argv[l][i] < '0' || argv[l][i] > '9') && argc > 2)
				ft_exit_2("Caracteres Erroneos");
			if ((argv[l][i] < '0' || argv[l][i] > '9') &&
				argv[l][i] != ' ' && argc < 3)
				ft_exit_2("Caracteres Erroneos");
			i++;
		}
		l++;
	}
}

int *list_gen(int argc, int cont, char **argv)
{
	int		i;
	int		*list;
	char	**list2;

	i = 0;
	if (argc == 2)
	{
		list2 = ft_split(argv[1], ' ');
		list = malloc(sizeof(int) * cont);
		if (list == NULL)
			ft_exit_2("Error Malloc");
		while (list2[i])
		{
			list[i] = ft_atoi(list2[i]);
			i++;
		}
		free(list2);
	}
	else
	{
		list = malloc(sizeof(int) * (argc - 1));
		if (list == NULL)
			ft_exit_2("Error Malloc");
		while (i < (argc - 1))
		{
			list[i] = atoi(argv[i + 1]);
			i++;
		}
	}
	return (list);
}

int	lista(int argc, char**argv)
{
	int	i;
	int	cont;

	i = 1;
	cont = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] == ' ' && (argv[1][i - 1] > '0' && argv[1][i] < '9'))
				cont++;
			i++;
		}
		if (argv[1][i - 1] > '0' && argv[1][i - 1] < '9')
			cont++;
	}
	printf("[%i]\n", cont);
	return (cont);
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
