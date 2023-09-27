/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:25:38 by aarrien-          #+#    #+#             */
/*   Updated: 2023/09/26 14:00:44 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	i = 0;
	if (len > ft_strlen(s))
		p = malloc(sizeof(char) * (ft_strlen(s) + 1));
	else
		p = malloc(sizeof(char) * (len + 1));
	if (p == 0)
		return (NULL);
	if (start < ft_strlen(s))
	{
		while (len > i && s[start + i])
		{
			p[i] = s[start + i];
			i++;
		}
	}
	p[i] = '\0';
	return (p);
}
