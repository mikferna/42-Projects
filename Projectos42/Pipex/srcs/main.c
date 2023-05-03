/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:01:27 by mikferna          #+#    #+#             */
/*   Updated: 2023/05/03 11:07:42 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
	{
		ft_exit_2("Error, use: ./pipex [file1] [cmd1] [cmd2] [file2]");
		exit(1);
	}
	else
		pipex(argv, envp);
	return (0);
}

void	first_child(int *fd, char **argv, char **envp, int open_fd)
{
	char	**comands;

	close(fd[0]);
	dup2(open_fd, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	comands = ft_split(argv[2], ' ');
	if (execve(path(comands[0], envp), comands, envp) == -1)
		ft_exit_2("Error en EXECVE");
	close(fd[1]);
}

void	father(int *fd, char **argv, char **envp, int close_fd)
{
	char	**comands;

	close(fd[1]);
	dup2(close_fd, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	comands = ft_split(argv[3], ' ');
	if (execve(path(comands[0], envp), comands, envp) == -1)
		ft_exit_2("Error en EXECVE");
	close(fd[0]);
}
