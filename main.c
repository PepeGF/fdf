#include "fdf.h"

#define MLX_ERROR 1
#define WIN_WIDTH 800
#define WIN_HEIGHT 600
//	%s///usleep/\/\///usleep/g
//	%s/\/\///usleep///usleep/g

/*	De momento este programa solo abre el archivo que contiene el mapa
 *	lo lee línea a línea
 *	cuenta cuántos puntos hay en la primera línea
 *	cuenta cuántas líneas hay
 *	y prepara un array de x*y para almacenar estructuras q contienen
 *	las coordenadas de los puntos y el color
 *
 *	La parte del array no sirve más que para pruebas básicas, no es un array lo
 *	que necesito, si no una matrix (array de arrays), que no se plantear
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

void	ft_get_map_size(t_coords *map, char *file)
{
	int		fd;
	char	*line;
	int		num_line;
/*
	//con esto habría que abrir el archivo 2 veces. NO quiero.
	//para no abrirlo 2 veces hay que almacenar las líneas en una lista
	//ese es el siguiente paso a implementar
	//
	//Hay que editar libft.h y hacer la estructura de lista cuyo contenido sea
	//un puntero a char y el puntero next.
	//Hay que hacer un malloc de la longitud bruta de la línea
	//		|_-> NO, eso ya lo hace GNL
	//xq vamos a almacenar el texto tal cual
	//dejar preparada una función para liberar la lista cuando ya se haya formado
	//la matrix de números
*/
	fd = open(file, O_RDONLY);
	num_line = 0;
	line = get_next_line(fd);
	map->x = ft_map_length(line);
	map->y = 0;
	while (line)
	{
		map->y++;
		free(line);
		line = get_next_line(fd);
		//aqui podría implementar una verificación de longitud de línea
		num_line++;
	}
	close(fd);
}

int	main(int argc, char *argv[])
{
	t_coords	maps;
	t_point		*points_array;

	if (argc != 2)
		return (33);//no va hacer nada
	ft_get_map_size(&maps, argv[1]);
	printf("x: %d, y: %d\n", maps.x, maps.y);
	points_array = malloc(sizeof(t_point *) * maps.x * maps.y);
	printf("%p\n", points_array);
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


