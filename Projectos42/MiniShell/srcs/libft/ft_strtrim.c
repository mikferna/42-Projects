/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:25:38 by aarrien-          #+#    #+#             */
/*   Updated: 2023/09/26 14:00:42 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	size_t	i;
	size_t	j;

	i = 0;
	if (!(*s1))
	{
		s = malloc(1);
		*s = '\0';
		return (s);
	}
	j = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[i]) && s1[i])
		i++;
	while (ft_strchr(set, s1[j]) && j > 0)
		j--;
	if (j == 0)
		i = 1;
	s = ft_substr(s1, i, j - i + 1);
	return (s);
}
