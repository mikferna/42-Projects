/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:33:14 by mikferna          #+#    #+#             */
/*   Updated: 2022/12/22 14:45:05 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

char	*leer_linea(int fd, char *line);
char	*escribir_linea_leida(char *document);
char	*borrar_linea_escrita(char *document);
char	*get_next_line(int fd);
char	*ft_strjoin(char *str1, char *str2);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);

#endif
