/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_node_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:15:54 by mikferna          #+#    #+#             */
/*   Updated: 2023/09/29 15:53:39 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	addback(t_env	*list, char *str)
{
	t_env	*c;

	while (list->next != NULL)
		list = list->next;
	c = malloc(sizeof(t_env));
	c->env = str;
	c->next = NULL;
	list->next = c;
}

t_env	*ft_lstnew(char *str)
{
	t_env	*new;

	new = (t_env *)malloc(sizeof(t_env));
	if (new == NULL)
		return (NULL);
	new->env = str;
	new->next = NULL;
	return (new);
}

int	ft_lstsize(t_env *lst)
{
	t_env	*tmp;
	int		i;

	i = 0;
	tmp = lst;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

char *stri(char *str, char c)
{
	char	*str2;
	int		i;
	int		len;

	i = 0;
	while (str && str[i] != c)
		i++;
	if (str && str[i] == '\0')
	{
		str2 = malloc(1);
		if (str2 == NULL)
			return NULL;
		str2[0] = '\0';
		return str2;
	}
	len = ft_strlen(str);
	str2 = malloc(sizeof(char) * (len - i + 1));
	if (str2 == NULL)
		return NULL;
	len = 0;
	while (str && str[i])
		str2[len++] = str[i++];
	str2[len] = '\0';
	return (str2);
}
