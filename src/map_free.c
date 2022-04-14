/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:53:19 by josgarci          #+#    #+#             */
/*   Updated: 2022/04/14 10:43:52 by josgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/*
 * Frees the list of lines
 */
void	ft_map_raw_free(t_list *raw_map)
{
	t_list	*aux;
	t_list	*aux2;

	aux = raw_map;
	while (aux)
	{
		aux2 = aux;
		free(aux->content);
		aux = aux->next;
		free(aux2);
	}
	free(aux);
	return ;
}

/*
 * Frees every matrix element and the matrix itself.
 */
void	ft_map_free_array(t_point **points, t_coord map_size)
{
	int	i;

	i = 0;
	while (i < map_size.y)
	{
		free(points[i]);
		i++;
	}
	free (points);
}
