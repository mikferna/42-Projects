/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:25:41 by mikferna          #+#    #+#             */
/*   Updated: 2023/06/15 11:25:23 by mikferna         ###   ########.fr       */
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

typedef struct s_list
{
	int				num;
	int				index;
	struct s_list	*next;
}	t_list;

/*-ps_main.c-*/
int		main(int argc, char **argv);

/*-ps_checker.c-*/
int		*dup_check(char **argv, int len);
int		check_sorted(char **argv, int i);
int		*checkers(int argc, char **argv);
void	ft_exit_2(char *str);
void	checker_comillas(char **argv);
int		space_tab_checker(char *str);

/*-ps_init.c-*/
void	init(int *argb, t_list **a);

/*-ps_movements.c-*/
void	sa(char **argv, t_list *a);

#endif