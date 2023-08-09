/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:11:14 by mikferna          #+#    #+#             */
/*   Updated: 2023/08/09 15:06:46 by mikferna         ###   ########.fr       */
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

//t_list **head;
//t_list b* = malloc(sizeof(t_list));
//head = &b;
//b = a->next;

///*-main.c-*/
int		main(int argc, char **argv);
///*-checkers.c-*/
void	checker(int argc, char **argv);
void	checker_characters(int argc, char **argv);
int		*list_gen(int argc, int cont, char **argv);
int		lista(int argc, char**argv);
void	ft_exit_2(char *str);


#endif