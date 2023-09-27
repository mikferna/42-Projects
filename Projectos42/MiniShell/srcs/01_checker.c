/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:02:12 by mikferna          #+#    #+#             */
/*   Updated: 2023/09/27 14:05:58 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_line_quote(char *s)
{
	int i;
	int quote;

	quote = 0;
	i = 0;
	if (!s)
		return (2);
	while (s && s[i])
	{
		if (s[i] == '\"' || s[i] == '\'')
			quote++;
		i++;
	}
	if (check_redirections(s) == 1)
		return (1);
	if (quote % 2 != 0)
		return (1);
	return (0);	
}

int	check_redirections(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if ((s[i] == '<' || s[i] == '>' || s[i] == '|') && (check_right(s, s[i], 0) == 1))
			return (1);
		i++;
	}
	return (0);
}

int	check_right(char *s, char w, int i)
{
	int chr;

	chr = 0;
	while (s[i] && (w == '<' || w == '>'))
	{
		if (s[i] != ' ' && s[i] != w)
			return (0);
		i++;
	}
	while (s[i] && w == '|')
	{
		if (s[i] != w && s[i] != ' ')
			chr = 1;
		if (s[i] == '|' && chr == 0)
			return (1);
		else if (s[i] == '|' && chr == 1)
			chr = 0;
		i++;
	}
	if (chr == 0 && s[i] == '\0')
		return (1);
	return (0);
}
