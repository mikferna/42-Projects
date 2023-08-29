/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:11:14 by mikferna          #+#    #+#             */
/*   Updated: 2023/08/29 17:09:13 by mikferna         ###   ########.fr       */
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

# define MAX_INT	2147483647
# define MIN_INT	-2147483647

typedef struct s_list
{
	int				num;
	int				index;
	int				relpos;
	int				maxmin;
	struct s_list	*next;
}	t_list;

///*-main.c-*/
int		main(int argc, char **argv);

///*-checkers.c-*/
t_list	*checker(int argc, char **argv);
void	checker_characters(int argc, char **argv);
t_list	*list_gen(int argc, int cont, char **argv, t_list *a);
int		lista(int argc, char**argv);
int		absolute(int num);

///*-node.c-*/
void	addback(t_list	*list, int value, int id);
t_list	*ft_lstnew(int num, int id);
int		node_numcheck(t_list	*list);
int		ft_lstsize(t_list *lst);
long	ft_atoil(const char *str);

///*-functions.c.c-*/
void	ft_exit_2(char *str);
void	atoi_check(char *num);
void	relative_calc(t_list *b);
void	findmaxmin(t_list *list);
void	relmaxmin(t_list *list);

///*-movements.c-*/
void	swap(t_list **list, char type);
void	rotate(t_list **list, char type);
void	revrotate(t_list **list, char type);
void	push(t_list **list1, t_list **list2, char type);
void	make_move(t_list **a, t_list **b, int rel);

///*-doublemovements.c-*/
void	doubleswap(t_list **list1, t_list **list2);
void	doublerotate(t_list **list1, t_list **list2);
void	doublerevrotate(t_list **list1, t_list **list2);
t_list	**indexor(t_list **a);

///*-algorithm.c-*/
void	algorithm(t_list **lst_a, t_list **lst_b);
void	three_nbr(t_list **list, char type);
void	five_nbr(t_list **list_a, t_list **list_b);
void	moves(t_list **list_a, t_list**list_b, int min, int max);

int		ft_printlist(t_list *lst);
int		ft_isordered(t_list *lst);

#endif