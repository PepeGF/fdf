#include "fdf.h"

//#include "/usr/include/X11/keysym.h"
#define MLX_ERROR 1
#define WIN_WIDTH 800
#define WIN_HEIGHT 600
//	%s///usleep/\/\///usleep/g
//	%s/\/\///usleep///usleep/g


/*
 *
 *
 *              * * * * * NO BORRAR ESTA PARTE * * * * * * * * 
 *
 * * * * puede ser util en el futuro para hacer listas de cosas complejas * * *
 * * * * sin necesidad de adaptar las funciones lstnew, lstaddback, etc * * * *
 *
 * Lee el mapa, cuenta las filas, las columnas, hace split de los elementos de
 * cada linea, saca su x su y y su z y os almacena en una estrucctura, con lo
 * escrito aqui el color se da por hecho que es 0.
 *
 * Se basa en usar esta estructura:
 *
 * //////////////////////////// *
 * typedef struct s_point
{
	int					x;
	int					y;
	int					z;
	unsigned int		color;
	struct s_point		*next;
}	t_point;
 * /////////////////////////// *

void print_lst(t_list **lst)
{
	t_list	*aux;

	aux = *lst;
	while (aux)
	{
		printf("x:%d, y:%d, z:%d, color:%d | ", ((t_point*)(aux->content))->x, ((t_point*)(aux->content))->y, ((t_point*)(aux->content))->z , ((t_point*)(aux->content))->color);
		aux=aux->next;
	}
}

int	map_length(char *line)
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

void	ft_split_mapline(char *line, t_list **point_lst, int num_line)
{
	int		i;
	int		j;
	char	**str;
	t_point	*point;

(void)j;
(void)point;
(void)point_lst;
(void)num_line;
	i = 0;
	str = ft_split(line, ' ');
	while (str && str[i] && (char)str[i] != '\n')
	{
		if (!ft_strchr(str[i], ',') && !ft_strchr(str[i], '\n'))
		{
			point = malloc(sizeof(t_point));
			point->x = i;
			point->y = num_line;
			point->z = ft_atoi(str[i]);
			point->color = 0;
			ft_lstadd_back(point_lst, (ft_lstnew((t_point*)point)));
		}
		else
		{
			//meter split para el color
		}
		free(str[i]);
		i++;
	}
	printf("\n");
	free(str);
}

void	get_map_size(t_coords *map, t_list **point, char *file)
{
	int		fd;
	char	*line;
	int		num_line;

	fd = open(file, O_RDONLY);
	num_line = 0;
	line = get_next_line(fd);
//	sleep(30);
	map->x = map_length(line);
	map->y = 0;
	while (line)
	{
		map->y++;
		ft_split_mapline(line, point, num_line);
		free(line);
		line = get_next_line(fd);
		num_line++;
	}
	print_lst(point);
	close(fd);
}

void	leaks(void)
{
	system ("leaks fdf");
}
int main(int argc, char *argv[])
{
	(void)argc;
	t_coords	map;
	t_list *point;

//	atexit(leaks);
	point = 0;
	get_map_size(&map, &point, argv[1]);
	printf("\nEje x: %d\nEje y: %d\n", map.x, map.y);
	printf("%lu\n",sizeof(t_point));
	return 0;
}
*/

/*
void	ft_split_mapline(char *line, int num_line)
{
	int			i;
	int			j;
	char		**str;
	t_coords	*point;
}
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





/*
 *
 *
 * * * * * * ESTA PARTE ES DE PRUEBAS DE MINILIBX * * * * * * *
 * 
 *
 * * * * * * * * * * * * no vale para mucho * * * * * * * * * * * * * 
 *
 *
 *
void	like_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	key_hook(int keycode, t_vars *vars)
{
	(void)vars;
	if (keycode == 53)
	{
		exit (0);
	}
	printf("Wololo!!!\n");
	return (0);
}

int	mouse_hook(int keycode, t_vars vars)
{
	(void) vars;
	if (keycode == 3)
	{
		exit (0);
	}
	else
	{
		printf("raton\n");
	}
	return (0);
}

void	leaks(void)
{
	system ("leaks --fullContent fdf > leak_report");
}

int	main(void)
{
	void	*mlx;
	void	*win;
	void	*win2;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "SUPER WOLOLO");
	win2 = mlx_new_window(mlx, 500, 500, "SUPER WOLOLO");
	mlx_string_put(mlx, win, 100, 100, 0xFFFFFF, "Mas wololo que nunca");
	mlx_string_put(mlx, win2, 100, 105, 0x01FF00FF, "Mas wololo que nunca");
	mlx_loop(mlx);
	atexit(leaks);
	return (0);
}
*/
/*
int	main(void)
{
	t_vars	vars;
	t_data	img;
	void	*ptr = malloc(19876);
	ptr = 0;

	atexit(leaks);

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "Wololo");
	img.img = mlx_new_image(vars.mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);
	like_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_key_hook(vars.win, &key_hook, &vars);//puede que el & de key_hook sobre
	mlx_mouse_hook(vars.win, &mouse_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
*/
int	rgb_to_int(int r, int g, int b)
{
	int	color;

	color = 0;
	color += (r << 16);
	color += (g << 8);
	color += b;
	return (color);
}


