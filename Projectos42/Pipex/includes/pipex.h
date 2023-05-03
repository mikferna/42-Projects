/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:53:17 by mikferna          #+#    #+#             */
/*   Updated: 2023/05/03 11:08:09 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>

/*-main.c-*/
int		main(int argc, char **argv, char **envp);
void	first_child(int *fd, char **argv, char **envp, int open_fd);
void	father(int *fd, char **argv, char **envp, int open_fd);

/*-functions.c-*/
void	ft_exit_2(char *str);
void	pipex(char **argv, char **envp);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);

/*-ft_split.c-*/
int		ft_doublesize(const char *s, char c);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	*ft_memcpy(void *dest, const void *src, size_t n);

/*-paths.c-*/
char	*path(char *cmd, char **envp);
char	**get_paths(char **envp);
char	*ft_strjoin(const char *s1, char const *s2);
void	cmd_not_found(char **cmd);

#endif