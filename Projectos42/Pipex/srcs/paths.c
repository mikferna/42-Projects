/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:01:06 by mikferna          #+#    #+#             */
/*   Updated: 2023/05/03 11:21:15 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_strjoin(const char *s1, char const *s2)
{
	int		t_len;
	char	*s3;
	size_t	n;
	size_t	m;

	if (!s2)
		return (ft_strdup(s1));
	if (!s1)
		return (ft_strdup(s2));
	n = 0;
	m = 0;
	t_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	s3 = malloc(t_len * sizeof(char));
	if (!s3)
		return (NULL);
	while (s1[m] != '\0')
		s3[n++] = s1[m++];
	m = 0;
	while (s2[m] != '\0')
		s3[n++] = s2[m++];
	s3[n] = '\0';
	return (s3);
}

void	free_split(char **args)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	while (args[size])
		size++;
	while (i < size)
		free(args[i++]);
	free(args);
}

void	cmd_not_found(char **cmd)
{
	write(2, cmd[0], ft_strlen(cmd[0]));
	write(2, ": command not found\n", 20);
	exit(1);
}

char	*path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	char	*slash;
	int		i;

	i = 0;
	if (ft_strnstr(cmd, "/", ft_strlen(cmd)))
		return (cmd);
	paths = get_paths(envp);
	i = -1;
	while (paths[++i])
	{
		slash = ft_strjoin(paths[i], "/");
		path = ft_strjoin(slash, cmd);
		free(slash);
		if (!access(path, F_OK))
		{
			free_split(paths);
			return (path);
		}
		free(path);
	}
	free_split(paths);
	cmd_not_found(&cmd);
	return (0);
}

char	**get_paths(char **envp)
{
	char	**paths;
	int		i;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH", 4))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	return (paths);
}
