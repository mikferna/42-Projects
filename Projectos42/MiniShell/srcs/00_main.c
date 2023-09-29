/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:59:02 by mikferna          #+#    #+#             */
/*   Updated: 2023/09/29 11:34:02 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_structs(t_ldata **line)
{
	line = malloc(sizeof(t_ldata));
}

int	main(int argc, char **argv, char **envp)
{
	t_ldata *line;

	if (argc != 1 || argv[1])
	{
		printf("This program does not accept arguments\n");
		exit(1);
	}
	init_structs(&line);
	while (1)
	{
		line->inp_line = readline("minishell> ");
		if (check_line_quote(line->inp_line) >= 1)
		{
			if (check_line_quote(line->inp_line) == 1)
				printf("Input Error\n");
			continue ;
		}
		if (*line->inp_line != 0)
			add_history(line->inp_line);
		else
			continue ;
		(void)envp;
		//programa
	}
	return (0);
}
