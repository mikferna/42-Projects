/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:25:41 by mikferna          #+#    #+#             */
/*   Updated: 2023/08/07 13:35:24 by mikferna         ###   ########.fr       */
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
int			main(int argc, char **argv);

/*-ps_checker.c-*/
int			*checker(int argc, char **argv);
void		cheker_comillas_arg(int argc, char **argv);
int			*cheker_dups_arg(int argc, char **argv);
void		cheker_order_arg(int argc, char **argv);
void		ft_exit_2(char *str);

/*-ps_checker2.c-*/
int			ft_check_elements(char **argv, int argc);
int			ft_isdigit(int c, int argc);
int			ft_check_maxint(char **argv);
long int	ft_long_atoi(const char *str);

/*-ps_init.c-*/
void		init(int *list);

/*-ps_movements.c-*/
void		sa(char **argv, t_list *a);

#endif