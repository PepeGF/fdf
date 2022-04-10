#include "../inc/fdf.h"

/* Función para guardar el mapa en memoria y no tener que abrir el archivo
 * del mapa varias veces
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

/* Esta función mira lo ancho que es el mapa (coord X) 
 * para el alto (Y) con contar los elementos de la lista de raw_map vale
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

void	ft_map_int_array(t_list *raw_map, t_point **points, t_coord map_size)
{
	char	**splited;
	t_list	*aux;
	int		j;
	int		i;
(void)map_size;
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
			// printf("%d|%d|%d ", points[i][j].x, points[i][j].y, points[i][j].z);
			free(splited[j]);
			j++;
		}
		free(splited);
		// printf("\n");
		i++;
		aux = aux->next;
	}
	// printf("***************************************************************\n");
}

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
