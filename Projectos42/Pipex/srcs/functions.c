/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:05:11 by mikferna          #+#    #+#             */
/*   Updated: 2023/05/03 11:07:39 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

size_t	ft_strlen(const char *str)
{
	int	c;

	c = 0;
	if (str == NULL)
		return (0);
	while (*str != '\0')
	{
		c++;
		str++;
	}
	return (c);
}

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

void	ft_exit_2(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	exit (2);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == '\0')
		return ((char *)haystack);

	if (ft_strlen(needle) > len)
		return (NULL);

	i = 0;
	while (i < len && haystack[i] != '\0')
	{
		j = 0;
		while (i + j < len && haystack[i + j] == needle[j] && needle[j] != '\0')
			j++;
		if (needle[j] == '\0')
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}

void	pipex(char **argv, char **envp)
{
	int		fd[2];
	int		open_fd;
	int		close_fd;
	pid_t	pid;

	if (pipe(fd) == -1)
		ft_exit_2("There has been an error opening the file");
	open_fd = open(argv[1], O_RDONLY);
	if (open_fd < 0)
		ft_exit_2("Error abriendo archivo");
	close_fd = open(argv[4], O_RDONLY | O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (write(close_fd, 0, 0) != 0)
		ft_exit_2("Error writing on the file");
	pid = fork();
	if (pid == 0)
		first_child(fd, argv, envp, open_fd);
	else if (pid < 0)
		perror("Error in the fork");
	else
		father(fd, argv, envp, close_fd);
}
