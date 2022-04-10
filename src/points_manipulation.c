#include "../inc/fdf.h"

/*
void	ft_print_points(t_point **points, t_coord map_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_size.y)
	{
		j = 0;
		while(j < map_size.x)
		{
			printf("%d|%d ",points[i][j].x_mod, points[i][j].y_mod);
			j++;
		}
		printf("\n");
		i++;
	}
	i = 0;
	while (i < map_size.y)
	{
		j = 0;
		while(j < map_size.x)
		{
			// printf("%d|%d ",points[i][j].x_mod, points[i][j].y_mod);
			printf("%d|%d|%d\t", points[i][j].x, points[i][j].y, points[i][j].z);
			j++;
		}
		printf("\n");
		i++;
	}
}
*/

void	ft_convert_points_2d(t_point **points, t_coord map_size)
{
	double	x_aux;
	double	y_aux;
	int		i;
	int		j;

	i = 0;
	while (i < map_size.y)
	{
		j = 0;
		while (j < map_size.x)
		{
			x_aux = sqrt(1.0 / 2) * (points[i][j].x - points[i][j].y);
			y_aux = sqrt(1.0 / 6) * (points[i][j].x + points[i][j].y
					- 2 * points[i][j].z);
			points[i][j].x = x_aux * 200;
			points[i][j].y = y_aux * 200;
			j++;
		}
		i++;
	}
	return ;
}

void	ft_adapt_pts_screen(t_point **points, t_data *data, t_coord map_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_size.y)
	{
		j = 0;
		while (j < map_size.x)
		{
			points[i][j].x_mod = data->scale * 0.9 * (points[i][j].x
					- data->map_center_x) + WIN_WIDTH / 2;
			points[i][j].y_mod = data->scale * 0.9 * (points[i][j].y
					- data->map_center_y) + WIN_HEIGHT / 2;
			j++;
		}
		i++;
	}
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
			x = points[i][j].x_mod;
			y = points[i][j].y_mod;
			if (x > 0 && x < WIN_WIDTH && y > 0 && y < WIN_HEIGHT)
				my_mlx_pixel_put(data, x, y, 0x00FFFFFF);
			j++;
		}
		i++;
	}
	return ;
}
