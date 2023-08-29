/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:32:32 by mikferna          #+#    #+#             */
/*   Updated: 2023/08/29 14:55:29 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*checker(int argc, char **argv)
{
	t_list	*a;
	int		cont;

	a = malloc(sizeof(t_list));
	checker_characters(argc, argv);
	cont = lista(argc, argv);
	a = list_gen(argc, cont, argv, a);
	if (node_numcheck(a) == 2)
		ft_exit_2("Numeros Repetidos");
	if (node_numcheck(a) == 1)
	{
		write(1, "\n", 2);
		exit(0);
	}
	return (a);
}

void	checker_characters(int argc, char **argv)
{
	int	i;
	int	l;

	l = 1;
	while (argv && l < argc)
	{
		i = 0;
		while (argv[l][i])
		{
			if (argv[l][i] == ' ' && argc > 2)
				ft_exit_2("Caracteres Erroneos");
			if ((argv[l][i] < '0' || argv[l][i] > '9') && argv[l][i] != ' ')
			{
				if (argv[l][i] != '-')
					ft_exit_2("Caracteres Erroneos");
				if (argv[l][i + 1] == '-')
					ft_exit_2("Caracteres Erroneos");
			}
			i++;
		}
		l++;
	}
}

t_list	*list_gen(int argc, int cont, char **argv, t_list *a)
{
	int		i;
	char	**list2;

	i = 0;
	if (argc == 2)
		list2 = ft_split(argv[1], ' ');
	else
	{
		list2 = malloc(sizeof(char *) * argc);
		if (list2 == NULL)
			ft_exit_2("Error Malloc List");
		list2 = argv;
		i++;
	}
	atoi_check(list2[i]);
	a = ft_lstnew(atoi(list2[i]), 0);
	i++;
	while ((i - 1 <= cont && list2[i]) || (i < argc && list2[i]))
	{
		atoi_check(list2[i]);
		addback(a, atoi(list2[i]), 0);
		i++;
	}
	return (a);
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
	return (cont);
}

int	absolute(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}
