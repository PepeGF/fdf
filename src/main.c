#include "../inc/fdf.h"

#define MLX_ERROR 1
#define WIN_WIDTH 1220
#define WIN_HEIGHT 750

void	leakss()
{
	system ("leaks fdf");
}

void	ft_print_points(t_point **points, t_coord map_size)
{
	int	i;
	int	j;

	i = 0;
	printf("Tamaño mapa: %dx%d\n", map_size.y, map_size.x);
	while (i < map_size.y)
	{
		j = 0;
		while(j < map_size.x)
		{
			//printf("%d|%d ",points[i][j].x, points[i][j].y);
			printf("%d ", points[i][j].y);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	key_hook(int keycode, t_data *data)
{
	(void)data;
	if (keycode == 53 || keycode == 12)
	{
		mlx_clear_window(data->mlx_ptr, data->mlx_win);
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		write(1, "Bye bye!\n", 9);
		exit (0);
	}
	else
		return (0);
}

void	ft_convert_points(t_point **points, t_coord map_size)
{
	double	x_aux;
	double	y_aux;
	int	i;
	int	j;

	i = 0;
	while (i < map_size.y)
	{
		j = 0;
		while (j < map_size.x)
		{
			x_aux = sqrt(1.0/2) * (points[i][j].x - points[i][j].y);
			y_aux = sqrt(1.0/6) * (points[i][j].x + points[i][j].y - 2* points[i][j].z);
			points[i][j].x = x_aux;
			points[i][j].y = y_aux;
			j++;
		}
		i++;
	}
	return ;
}

void	ft_draw_line(t_point **points, t_data *data, t_coord map_size)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	while (i < map_size.y)
	{
		j = 0;
		while (j < map_size.x)
		{
			x = points[i][j].x;
			y = points[i][j].y;
			my_mlx_pixel_put(data, data->scale * 0.9 * (x - data->map_center_x) + 1220/2  , data->scale * 0.9 * (y - data->map_center_y) +750/2 , 0x00FFFFFF);
			j++;
		}
		i++;
	}
	return ;
}

void	ft_map_middle_x(t_point **points, t_coord map_size, t_data *data)
{
	int	i;
	int	j;
	double	x_max;
	double	x_min;

	x_max = points[0][0].x;
	x_min = points[0][0].x;
	i = 0;
	while (i < map_size.y)
	{
		j = 0;
		while (j < map_size.x)
		{
			if (points[i][j].x > x_max)
				x_max = points[i][j].x;
			if (points[i][j].x < x_min)
				x_min = points[i][j].x;
			j++;
		}
		i++;
	}
	data->map_center_x = (x_max + x_min) / 2.0;
	data->map_dimension_x = x_max - x_min;
	printf("x_max:%f x_min:%f\n", x_max, x_min);
}

void	ft_map_middle_y(t_point **points, t_coord map_size, t_data *data)
{
	int	i;
	int	j;
	double	y_max;
	double	y_min;


	y_max = points[0][0].y;
	y_min = points[0][0].y;
	i = 0;
	while (i < map_size.y)
	{
		j = 0;
		while (j < map_size.x)
		{
			if (points[i][j].y > y_max)
				y_max = points[i][j].y;
			if (points[i][j].y < y_min)
				y_min = points[i][j].y;
			j++;
		}
		i++;
	}
	data->map_center_y = (y_max + y_min) / 2.0;
	data->map_dimension_y = y_max - y_min;
}

void	ft_get_scale(t_data *data)
{
	int	vertical_scale;
	int	horizontal_scale;

	vertical_scale = WIN_HEIGHT / data->map_dimension_y;
	horizontal_scale = WIN_WIDTH / data->map_dimension_x;
	if (vertical_scale > horizontal_scale)
		data->scale = horizontal_scale;
	else
		data->scale = vertical_scale;
	printf("Mapa dibujado X: %d\nMapa dibujado Y: %d\n", data->map_dimension_x,data->map_dimension_y);
	printf("Escala vertical: %d\nEscala Horizontal: %d\n", vertical_scale, horizontal_scale);
	printf("Escala global: %d\n", data->scale);
}

int	main(int argc, char *argv[])
{
	t_list		*raw_map;
	t_point		**points;
	t_coord		map_size;
	t_data		data;
	//int	i = 0;


	atexit(leakss);
	if (argc != 2)
		return (33);
	raw_map = NULL;
	//funcion para inicializar data en cero???
	ft_map_read(&raw_map, argv[1]);
	map_size.x = ft_map_length(raw_map->content);
	map_size.y = ft_lstsize(raw_map);
	ft_map_create_array(&points, map_size);
	ft_map_int_array(raw_map, points);
	ft_map_raw_free(raw_map);
	ft_print_points(points, map_size);
	ft_convert_points(points, map_size);
	ft_print_points(points, map_size);
	ft_map_middle_x(points, map_size, &data);
	ft_map_middle_y(points, map_size, &data);
	ft_get_scale(&data);

	data.mlx_ptr = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx_ptr, 1220, 750, "Wololo!");
	data.img = mlx_new_image(data.mlx_ptr, 1220, 750);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_lenght, &data.endian);
	ft_draw_line(points, &data, map_size);
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.img, 0, 0);
	mlx_key_hook(data.mlx_win, &key_hook, &data);
	//system("leaks fdf");
	mlx_loop(data.mlx_ptr);

	ft_map_free_array(points, map_size);
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
