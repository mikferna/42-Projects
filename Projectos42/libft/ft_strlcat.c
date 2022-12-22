/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:18:21 by mikferna          #+#    #+#             */
/*   Updated: 2022/10/14 13:59:51 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dest;
	size_t	orig;
	size_t	i;

	i = 0;
	orig = ft_strlen(src);
	dest = ft_strlen(dst);
	if (dstsize == 0 || dstsize <= dest)
	{
		return (dstsize + orig);
	}
	while (i < (dstsize - dest - 1) && src[i])
	{
		dst[dest + i] = src[i];
		i++;
	}
	dst[dest + i] = '\0';
	return (dest + orig);
}
