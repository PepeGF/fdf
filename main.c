#include "fdf.h"

//#include "/usr/include/X11/keysym.h"
#define MLX_ERROR 1
#define WIN_WIDTH 800
#define WIN_HEIGHT 600
//	%s///usleep/\/\///usleep/g
//	%s/\/\///usleep///usleep/g

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
		//aqui deberia obtener la y de cada punto
		i++;
	}
	length++;
	return (length);
}

void	get_map_size(t_coords *map, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	//aqui deberia obtener la x de cada punto
	map->x = map_length(line);
	map->y = 0;
	while (line)
	{
		map->y++;
		line = get_next_line(fd);
	}
	close(fd);
}

int main(int argc, char *argv[])
{
	(void)argc;
	t_coords	map;

	get_map_size(&map, argv[1]);
	printf("Eje x: %d\nEje y: %d\n", map.x, map.y);
	return 0;
}

/*
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


