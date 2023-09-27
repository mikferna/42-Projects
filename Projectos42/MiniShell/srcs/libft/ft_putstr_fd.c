/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:25:38 by aarrien-          #+#    #+#             */
/*   Updated: 2023/09/26 14:00:31 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == 17)
		{
			ft_putchar_fd('>', fd);
			i++;
		}
		if (s[i] == 18)
		{
			ft_putchar_fd('<', fd);
			i++;
		}
		if (s[i] == 16)
		{
			ft_putchar_fd('|', fd);
			i++;
		}
		else
			ft_putchar_fd(s[i++], fd);
	}
}
