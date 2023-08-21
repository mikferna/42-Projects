/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:11:14 by mikferna          #+#    #+#             */
/*   Updated: 2023/08/21 12:27:56 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include "../srcs/libft/libft.h"

typedef struct s_list
{
	int				num;
	int				index;
	struct s_list	*next;
}	t_list;

///*-main.c-*/
int		main(int argc, char **argv);
///*-checkers.c-*/
void	checker(int argc, char **argv, t_list *a);
void	checker_characters(int argc, char **argv);
t_list	*list_gen(int argc, int cont, char **argv, t_list *a);
int		lista(int argc, char**argv);
void	ft_exit_2(char *str);
///*-node.c-*/
void	addback(t_list	*list, int value, int id);
t_list	*ft_lstnew(int num, int id);
int		node_numcheck(t_list	*list);

#endif