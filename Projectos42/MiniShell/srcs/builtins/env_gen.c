/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:21:44 by mikferna          #+#    #+#             */
/*   Updated: 2023/09/29 15:23:01 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_env	*get_env(char **envp, t_env *env)
{
	int		i;
	t_env	*temp;

	ft_lstnew(envp[0]);
	temp = env;
	i = 1;
	while (envp[i])
	{
		addback(temp, envp[i]);
		i++;
	}
	return (env);
}
