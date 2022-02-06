/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 08:06:13 by josgarci          #+#    #+#             */
/*   Updated: 2022/01/16 13:21:24 by josgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_split_line(char **rest, int first_n);
char	*ft_readtext(int fd, int *first_n, char **rest, size_t *lenrest);
char	*ft_fill_buffer(char *buffer, int *lenread, int fd);

char	*get_next_line(int fd)
{
	static char	*rest;
	int			first_n;
	size_t		lenrest;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) == -1)
		return (0);
	lenrest = ft_strlen_gnl(rest);
	first_n = ft_strchr_gnl(rest, 10);
	if (first_n != -1)
		return (ft_split_line(&rest, first_n));
	if (!ft_readtext(fd, &first_n, &rest, &lenrest))
	{
		if (rest)
			free(rest);
		return (0);
	}
	else
		return (ft_split_line(&rest, first_n));
}

char	*ft_readtext(int fd, int *first_n, char **rest, size_t *lenrest)
{
	char	*buffer;
	char	*aux;
	int		lenread;

	while (*first_n == -1)
	{
		buffer = ft_fill_buffer(buffer, &lenread, fd);
		if (lenread == -1 || (lenread == 0 && *lenrest == 0))
		{
			free (buffer);
			return (0);
		}
		*lenrest += lenread;
		*first_n = ft_strchr_gnl(buffer, 10);
		if (*first_n != -1)
			*first_n = *first_n + *lenrest - lenread - 0;
		aux = ft_strjoin_gnl(*rest, buffer);
		free(buffer);
		if (*rest)
			free(*rest);
		*rest = aux;
		if ((*first_n == -1 && lenread < BUFFER_SIZE) || lenread == 0)
			*first_n = *lenrest;
	}
	return (*rest);
}

char	*ft_fill_buffer(char *buffer, int *lenread, int fd)
{
	buffer = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	ft_bzero_gnl (buffer, BUFFER_SIZE + 1);
	*lenread = read (fd, buffer, BUFFER_SIZE);
	return (buffer);
}

char	*ft_split_line(char **rest, int first_n)
{
	char	*line;
	char	*aux;

	line = ft_substr_gnl(*rest, 0, first_n + 1);
	aux = ft_substr_gnl(*rest, first_n + 1, ft_strlen_gnl(*rest) - first_n - 1);
	free (*rest);
	*rest = aux;
	return (line);
}
