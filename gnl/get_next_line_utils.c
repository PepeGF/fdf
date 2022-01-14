/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 09:59:42 by josgarci          #+#    #+#             */
/*   Updated: 2021/11/25 13:11:01 by josgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)str)[i] = '\0';
		i++;
	}
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i] != '\0' && s[i] != (unsigned char)c)
		i++;
	if (s[i] == (unsigned char)c)
		return (i);
	return (-1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	len_s;

	i = 0;
	if (!s)
		return (0);
	len_s = ft_strlen(s);
	if (start >= len_s)
		len = 0;
	if (len > len_s)
		len = len_s;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (0);
	ft_bzero (str, len + 1);
	if (len == 0)
		return (str);
	while (i < len && i + start < len_s)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	s1len;
	size_t	s2len;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (s1len + s2len + 1));
	if (!str)
		return (0);
	ft_bzero(str, s1len + s2len + 1);
	i = -1;
	while (++i < s1len)
		str[i] = s1[i];
	i = -1;
	while (++i < s2len)
		str[i + s1len] = s2[i];
	return (str);
}
