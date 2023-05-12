/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 10:53:18 by mikferna          #+#    #+#             */
/*   Updated: 2022/10/14 14:00:00 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*memory;

	i = ft_strlen(s1);
	memory = malloc(i + 1);
	if (memory == NULL)
		return (0);
	memory[i] = '\0';
	return (ft_memcpy(memory, s1, i));
}
