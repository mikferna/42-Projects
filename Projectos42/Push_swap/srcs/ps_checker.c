/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:36:31 by mikferna          #+#    #+#             */
/*   Updated: 2023/05/10 14:03:08 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	dup_check(char **argv, int len, t_main *datos)
{
	int	i;
	int	j;

	len = 0;
	while (argv[len])
		len++;
	datos->a = malloc(sizeof(int) * len);
	i = 0;
	while (argv[++i])
		datos->a[i - 1] = ft_atoi(argv[i]);
	i = -1;
	while (++i < len - 1)
	{
		j = i;
		while (++j < len)
		{
			if (datos->a[j] == datos->a[i] || datos->a[i] < 0)
			{
				free(datos->a);
				ft_exit_2("Numeros Duplicados O Negativos");
			}
		}
	}
	free(datos->a);
}

int	check_sorted(char **argv)
{
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

void	checkers(int argc, char **argv, t_main *datos)
{
	(void)argc;
	dup_check(argv, 0, datos);
	if (!check_sorted(&argv[1]))
		ft_exit_2("Lista Ordenada");
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
