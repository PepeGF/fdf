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
		printf("%s", aux->content);
		aux2 = aux;
		free(aux->content);
		aux = aux->next;
		free(aux2);
	}
	free(aux);
	return ;
}

void	ft_prepare_map(t_list *raw_map, t_point **points)
{
	t_list	*aux;
	int		i;
	t_coord	coord;

	(void)points;
	aux = raw_map;
	coord.x = 0;
	coord.y = 0;
	while (aux)
	{
		i = 0;
		(coord.y)++;
		while ((aux->content)[i] != '\n')
		{

			i++;
		}
		aux = aux->next;
	}
}

int	main(int argc, char *argv[])
{
	t_list		*raw_map;
	t_point		*points;

	if (argc != 2)
		return (33);
	raw_map = 0;
	points = 0;
	ft_save_map(&raw_map, argv[1]);
	ft_prepare_map(raw_map, &points);
	ft_free_map(raw_map);
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
