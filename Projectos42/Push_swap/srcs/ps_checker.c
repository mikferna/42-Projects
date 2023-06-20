/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:36:31 by mikferna          #+#    #+#             */
/*   Updated: 2023/06/15 11:21:13 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*dup_check(char **argv, int len)
{
	int	i;
	int	j;
	int	*a;
	int *argb;

	len = 0;
	while (argv[len])
		len++;
	a = malloc(sizeof(int) * len);
	i = 0;
	while (argv[++i])
		a[i - 1] = ft_atoi(argv[i]);
	i = -1;
	while (++i < len - 1)
	{
		j = i;
		while (++j < len)
		{
			if (a[j] == a[i])
			{
				free(a);
				ft_exit_2("Numeros Duplicados");
			}
		}
	}
	argb = a;
	free(a);
	return (argb);
}

int	check_sorted(char **argv, int i)
{
	//printf("[%i]", i);
	if (i == 1)
		argv = ft_split(argv[1], ' ');
	while (*argv)
	{
		if (!argv[1])
			return (0);
		if (ft_atoi(*argv) < ft_atoi(argv[1]))
			argv++;
		else
			return (1);
	}
	return (0);
}


void	checker_comillas(char **argv)
{
	int		i;
	int		l;
	int		num;

	i = 0;
	l = 2;
	num = 0;
	while (argv[l] && argv[1][0] == '"')
	{
		i = 0;
		while (argv[l][i])
		{
			if (argv[l][i] == ' ' || (argv[l][i] >= '0' && argv[l][i] <= '9'))
				ft_exit_2("Argumentos erroneos");
			i++;
		}
		l++;
	}
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

int	*checkers(int argc, char **argv)
{
	char	**arguments;
	int		*argb;

	if (argc >= 3)
		checker_comillas(argv);
	if (argc == 2 && space_tab_checker(argv[3]))
	{
		arguments = ft_split(argv[1], ' ');
		argb = dup_check(arguments, 0);
		if (!check_sorted(argv, 1))
			ft_exit_2("Lista Ordenada");
	}
	else
	{
		argb = dup_check(argv, 0);
		if (!check_sorted(argv, 0))
			ft_exit_2("Lista Ordenada");
	}
	return (argb);
}

int	space_tab_checker(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] != ' ' && str[i] != '	')
			return (1);
		i++;
	}
	return (0);
}
