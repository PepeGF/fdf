#include "../inc/fdf.h"

void	leakss()
{
	system ("leaks fdf");
}

/*
void ft_decide_v_h(t_point **points, t_data *data, t_coord map_size)
{
	//int	i = 0;
	//int	j = 0;
	int	x[2];
	int	y[2];
	int slope;

	x[0] = points[0][0].x;
	x[1] = points[10][18].x;
	y[0] = points[0][0].y;
	y[1] = points[10][18].y;
	if ( x[1] - x[0] == 0)
		slope = 0;
	else
		slope = abs((y[1] - y[0]) / (x[1] - x[0]));
	(void)data;
	(void)map_size;
	printf("Pendiente = %d\n", slope);
	if (slope > 1 )
		ft_draw_line_high(points, data, map_size);
	else
		ft_draw_line_low(points, data, map_size);
}
*/

void	ft_bresen_pos_high(t_data *data, t_point point0, t_point point1)
{
	int	d[3];
	int coord[2];

	d[0] = point1.x - point0.x;
	d[1] = point1.y - point0.y;
	coord[0] = point0.x;
	coord[1] = point0.y;
	d[2] = 2 * d[0] - d[1];
	while (coord[1] < point1.y)
	{
		if (d[2] >= 0)
		{
			my_mlx_pixel_put(data, coord[0], coord[1], 0x00FFFFFF);
			coord[0]++;
			d[2] = d[2] + 2 * d[0] - 2 * d[1];
		}
		else
		{
			my_mlx_pixel_put(data, coord[0], coord[1], 0x00FFFFFF);
			d[2] = d[2] + 2 * d[0];
		}
		coord[1]++;
	}
}

int	main(int argc, char *argv[])
{
	t_list		*raw_map;
	t_point		**points;
	t_coord		map_size;
	t_data		data;

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
	//ft_map_raw_free(raw_map);
	ft_convert_points(points, map_size);
	ft_map_middle_x(points, map_size, &data);
	ft_map_middle_y(points, map_size, &data);
	ft_get_scale(&data);

	data.mlx_ptr = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "FDF");
	data.img = mlx_new_image(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_lenght, &data.endian);
	
	points[0][0].x = 10;
	points[0][0].y = 500;
	points[1][1].x = 100;
	points[1][1].y = 10;
	ft_bresen_pos_high(&data, points[0][0], points[1][1]);
	my_mlx_pixel_put(&data, points[0][0].x, points[0][0].y, 0xff0000);
	my_mlx_pixel_put(&data, points[1][1].x, points[1][1].y, 0xff0000);

	//system ("leaks fdf");
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.img, 0, 0);
	mlx_key_hook(data.mlx_win, &key_hook, &data);
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
