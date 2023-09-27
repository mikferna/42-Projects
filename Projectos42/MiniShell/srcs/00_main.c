/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:59:02 by mikferna          #+#    #+#             */
/*   Updated: 2023/09/27 13:51:27 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char *s;

	if (argc != 1 || argv[1])
	{
		printf("This program does not accept arguments\n");
		exit(1);
	}
	while (1)
	{
		s = readline("minishell> ");
		if (check_line_quote(s) >= 1)
		{
			if (check_line_quote(s) == 1)
				printf("Input Error\n");
			continue ;
		}
		if (*s != 0)
			add_history(s);
		else
			continue ;
		//programa
	}
	printf("%s\n", envp[0]);
	return (0);
}
