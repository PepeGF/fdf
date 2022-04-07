#include "../inc/fdf.h"

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
			printf("%d|%d ",points[i][j].x, points[i][j].y);
			//printf("%d ", points[i][j].y);
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
	if (keycode == 53 || keycode == 12)
	{
		mlx_clear_window(data->mlx_ptr, data->mlx_win);
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		write(1, "Bye bye!\n", 9);
		exit (0);
	}
	else if (keycode == 30)
	{
//		data->scale+=10;
//		mlx_clear_window(data->mlx_ptr, data->mlx_win);
		printf("Aumentar zoom, ya veremos cómo\n");		
	}
	else if (keycode == 44)
	{
		printf("Disminuir zoom, ya veremos cómo\n");
	}
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
			y_aux = sqrt(1.0/6) * (points[i][j].x + points[i][j].y - 2 * points[i][j].z);
			points[i][j].x = x_aux;
			points[i][j].y = y_aux;
			j++;
		}
		i++;
	}
	return ;
}

void	ft_draw_vertex(t_point **points, t_data *data, t_coord map_size)
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
			x = data->scale * 0.9 * (points[i][j].x - data->map_center_x) + WIN_WIDTH/2;
			y = data->scale * 0.9 * (points[i][j].y - data->map_center_y) + WIN_HEIGHT/2;
			if (x > 0 && x < WIN_WIDTH && y > 0 && y < WIN_HEIGHT)
			my_mlx_pixel_put(data, x, y, 0x00FFFFFF);
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
//	printf("x_max:%f x_min:%f\n", x_max, x_min);
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
	double vertical_scale;
	double	horizontal_scale;

	vertical_scale = (WIN_HEIGHT - 0.0) / data->map_dimension_y;
	horizontal_scale = (WIN_WIDTH - 0.0) / data->map_dimension_x;
	if (vertical_scale > horizontal_scale)
		data->scale = horizontal_scale;
	else
		data->scale = vertical_scale;
//	printf("Mapa dibujado X: %d\nMapa dibujado Y: %d\n", data->map_dimension_x,data->map_dimension_y);
//	printf("Escala vertical: %f\nEscala Horizontal: %f\n", vertical_scale, horizontal_scale);
//	printf("Escala global: %f\n", data->scale);
}

void	ft_bresen_pos_low(t_data *data, t_point point0, t_point point1)
{
	int	d[3];
	int coord[2];

	d[0] = point1.x - point0.x;
	d[1] = point1.y - point0.y;
	coord[0] = point0.x;
	coord[1] = point0.y;
	d[2] = 2 * d[1] - d[0];
	while (coord[0] < point1.x)
	{
		if (d[2] >= 0)
		{
			my_mlx_pixel_put(data, coord[0], coord[1], 0x00FFFFFF);
			coord[1]++;
			d[2] = d[2] + 2 * d[1] - 2 * d[0];
		}
		else
		{
			my_mlx_pixel_put(data, coord[0], coord[1], 0x00FFFFFF);
			d[2] = d[2] + 2 * d[1];
		}
		coord[0]++;
	}
}

void	ft_bresen_neg_low(t_data *data, t_point point0, t_point point1)
{
	int	d[3];
	int coord[2];

	d[0] = point1.x - point0.x;
	d[1] = point1.y - point0.y;
	coord[0] = point0.x;
	coord[1] = point0.y;
	d[2] = 2 * d[1] - d[0];
	while (coord[0] < point1.x)
	{
		if (d[2] >= 0)
		{
			my_mlx_pixel_put(data, coord[0], coord[1], 0x00FFFFFF);
			coord[1]--;
			d[2] = d[2] - 2 * d[1] - 2 * d[0];
		}
		else
		{
			my_mlx_pixel_put(data, coord[0], coord[1], 0x00FFFFFF);
			d[2] = d[2] - 2 * d[1];
		}
		coord[0]++;
	}
}
