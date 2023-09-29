/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:11:51 by mikferna          #+#    #+#             */
/*   Updated: 2023/09/29 12:26:53 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	home_cd(t_env *env)
{
	
	return (0);
}

int	cd(t_env *env, char **args)
{
	int	i;

	i = 0;
	if (!args[1] || args[1][0] == '~')
		i = home_cd(env);
	return (i);
}