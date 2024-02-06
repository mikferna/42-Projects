/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:32:35 by mikferna          #+#    #+#             */
/*   Updated: 2023/01/20 13:30:57 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*documento_guardado;
	char		*linea;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	documento_guardado = read_save(fd, documento_guardado);
	if (!documento_guardado)
		return (NULL);
	linea = devolver_linea(documento_guardado);
	documento_guardado = borrar_linea(documento_guardado);
	return (linea);
}

char	*read_save(int fd, char *linea)
{
	char	*buff;
	int		e;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	e = 1;
	while (!ft_strchr(linea, '\n') && e)
	{
		e = read(fd, buff, BUFFER_SIZE);
		if (e == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[e] = '\0';
		linea = ft_strjoin(linea, buff);
	}
	free(buff);
	return (linea);
}

char	*devolver_linea(char *documento)
{
	int		cont;
	char	*linea_escrita;

	cont = 0;
	if (!documento[cont])
		return (NULL);
	while (documento[cont] != '\n' && documento[cont] != '\0')
		cont ++;
	linea_escrita = malloc(sizeof(char) * cont + 2);
	if (!linea_escrita)
		return (NULL);
	cont = 0;
	while (documento[cont] && documento[cont] != '\n')
	{
		linea_escrita[cont] = documento[cont];
		cont++;
	}
	if (documento[cont] == '\n')
	{
		linea_escrita[cont] = documento[cont];
		cont++;
	}
	linea_escrita[cont] = '\0';
	return (linea_escrita);
}

char	*borrar_linea(char *documento)
{
	char	*new_documento;
	int		cont1;
	int		cont2;

	cont1 = 0;
	while (documento[cont1] && documento[cont1] != '\n')
		cont1++;
	if (!documento[cont1])
	{
		free(documento);
		return (NULL);
	}
	new_documento = malloc(sizeof(char) * (ft_strlen(documento) - cont1 + 1));
	if (!new_documento)
		return (NULL);
	cont1++;
	cont2 = 0;
	while (documento[cont1])
		new_documento[cont2++] = documento[cont1++];
	new_documento[cont2] = '\0';
	free (documento);
	return (new_documento);
}
