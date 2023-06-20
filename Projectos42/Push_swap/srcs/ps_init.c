/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:20:03 by mikferna          #+#    #+#             */
/*   Updated: 2023/06/15 11:25:15 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void init(int *argb, t_list **a) {
    int i = 0;

    *a = malloc(sizeof(t_list));
    (*a)->num = argb[i];
    (*a)->index = i;
    (*a)->next = NULL;

    t_list *temp = *a;

    i++;

    while (argb[i] != 0) {
        temp->next = malloc(sizeof(t_list));
        temp = temp->next;
        temp->num = argb[i];
        temp->index = i;
        temp->next = NULL;

        i++;
    }
}