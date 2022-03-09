#include "fdf.h"

#define MLX_ERROR 1
#define WIN_WIDTH 800
#define WIN_HEIGHT 600
//	%s///usleep/\/\///usleep/g
//	%s/\/\///usleep///usleep/g

/*	De momento este programa solo abre el archivo que contiene el mapa
 *	lo lee línea a línea
 *
 *
 */

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

/* Función para guardar el mapa en memoria y no tener que abrir el archivo
 * del mapa varias veces
 */
void	ft_save_map(t_list **raw_map, char *file)
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

/* Función para liberar raw_map cuando no sea necesario usarlo más */
void	ft_free_map(t_list *raw_map)
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

void	ft_prepare_map(t_list *raw_map, t_point ***points, t_coord map_size)
{
	char	**splited;
	t_list	*aux;
	int		k;
	int		j;
	int		i;

	*points = malloc(sizeof(t_point *) * map_size.y);
	k = 0;
	aux = raw_map;
	while (aux)
	{
		splited = ft_split(aux->content);
		while (splited[k])
		{
			while (i < map)
			*points[i][j]
			i++;
		}
		aux = aux->next;
	}

	(void)raw_map;
	(void)points;
	(void)map_size;



	
}

int	main(int argc, char *argv[])
{
	t_list		*raw_map;
	t_point		**points;
	t_coord		map_size;

	if (argc != 2)
		return (33);
	raw_map = 0;
//	points = 0;
//	(void)points;
	ft_save_map(&raw_map, argv[1]); //cambiar en fdf.h
	map_size.x = ft_map_length(raw_map->content);
	map_size.y = ft_lstsize(raw_map);
	ft_prepare_map(raw_map, &points, map_size);	
	int	i;
	int j;

	i = 0;
	points = malloc(sizeof(t_point *) * map_size.y);
	while (i < map_size.y)
	{
		points[i] = malloc(sizeof(t_point) * map_size.x);
		i++;
	}
	i = 0;
	while (i < map_size.y)
	{
		j = 0;
		while (j < map_size.x)
		{
			points[i][j].x = i + 1;
			points[i][j].y = j + 1;
			printf("%d|%d ", points[i][j].x, points[i][j].y);
//			printf("%p  ", &points[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}


	ft_free_map(raw_map);
	//función liberar matriz
	return (0);
}

int	rgb_to_int(int r, int g, int b)
{
	int	color;

	color = 0;
	color += (r << 16);
	color += (g << 8);
	color += b;
	return (color);
}
