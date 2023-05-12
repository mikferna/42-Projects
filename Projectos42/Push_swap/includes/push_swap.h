/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:25:41 by mikferna          #+#    #+#             */
/*   Updated: 2023/05/10 14:02:29 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../srcs/libft/libft.h"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>

typedef struct s_main
{
	int	*a;
	int	*b;
}	t_main;

/*-ps_main.c-*/
int		main(int argc, char **argv);

/*-ps_checker.c-*/
void	dup_check(char **argv, int len, t_main *datos);
int		check_sorted(char **argv);
void	checkers(int argc, char **argv, t_main *datos);
void	ft_exit_2(char *str);

#endif