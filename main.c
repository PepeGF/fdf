#include "fdf.h"

//#include "/usr/include/X11/keysym.h"
#define MLX_ERROR 1
#define WIN_WIDTH 800
#define WIN_HEIGHT 600
//	%s///usleep/\/\///usleep/g
//	%s/\/\///usleep///usleep/g

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
		num_line++;
	}
	close (fd);
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


