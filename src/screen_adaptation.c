#include "../inc/fdf.h"

void	ft_map_middle_x(t_point **points, t_coord map_size, t_data *data)
{
	int		i;
	int		j;
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
}

void	ft_map_middle_y(t_point **points, t_coord map_size, t_data *data)
{
	int		i;
	int		j;
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
	double	vertical_scale;
	double	horizontal_scale;

	vertical_scale = (WIN_HEIGHT - 0.0) / data->map_dimension_y;
	horizontal_scale = (WIN_WIDTH - 0.0) / data->map_dimension_x;
	if (vertical_scale > horizontal_scale)
		data->scale = horizontal_scale;
	else
		data->scale = vertical_scale;
}
