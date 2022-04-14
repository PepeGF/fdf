/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:54:16 by josgarci          #+#    #+#             */
/*   Updated: 2022/04/14 10:52:39 by josgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/* 
 * Function to keep map in memory and avoid open the file more than once
 * Each line is allocated and added at the end of a list
 */
void	ft_map_read(t_list **raw_map, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(1);
	line = get_next_line(fd);
	while (line)
	{
		ft_lstadd_back(raw_map, ft_lstnew(line));
		line = get_next_line(fd);
	}
	close(fd);
	return ;
}

/* 
 * This function counts how many elements are in the X axis
 */
int	ft_map_length(char *line)
{
	int	length;
	int	i;

	length = 0;
	i = 0;
	while (line[i] == ' ')
		i++;
	while (line[i])
	{
		if (line[i] == ' ' && line[i + 1] != ' ' && line[i + 1] != '\n')
			length++;
		i++;
	}
	length++;
	return (length);
}

/* 
 * This function writes the 3D coord of each point into the matrix.
 * It splits every line and makes and atoi to save the Z coord.
 */
void	ft_map_int_array(t_list *raw_map, t_point **points)
{
	char	**splited;
	t_list	*aux;
	int		j;
	int		i;

	aux = raw_map;
	i = 0;
	while (aux)
	{
		splited = ft_split(aux->content, ' ');
		j = 0;
		while (splited[j])
		{
			points[i][j].x = j;
			points[i][j].y = i;
			points[i][j].z = ft_atoi(splited[j]);
			free(splited[j]);
			j++;
		}
		free(splited);
		i++;
		aux = aux->next;
	}
}

/*
 * To allocate memory for the matrix and its elements.
 * Each element is and struct which contains xyz and xy_mod
 */
void	ft_map_create_array(t_point ***points, t_coord map_size)
{
	int	i;

	i = 0;
	*points = malloc(sizeof(t_point *) * map_size.y);
	while (i < map_size.y)
	{
		(*points)[i] = malloc(sizeof(t_point) * map_size.x);
		i++;
	}
}
