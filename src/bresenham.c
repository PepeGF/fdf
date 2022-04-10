#include "../inc/fdf.h"

void	ft_bresen_pos_low(t_data *data, t_point point0, t_point point1)
{
	int	d[3];
	int	coord[2];

	d[0] = point1.x_mod - point0.x_mod;
	d[1] = point1.y_mod - point0.y_mod;
	coord[0] = point0.x_mod;
	coord[1] = point0.y_mod;
	d[2] = 2 * d[1] - d[0];
	while (coord[0] < point1.x_mod)
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

void	ft_bresen_pos_high(t_data *data, t_point point0, t_point point1)
{
	int	d[3];
	int	coord[2];

	d[0] = point1.x_mod - point0.x_mod;
	d[1] = point1.y_mod - point0.y_mod;
	coord[0] = point0.x_mod;
	coord[1] = point0.y_mod;
	d[2] = 2 * d[0] - d[1];
	while (coord[1] < point1.y_mod)
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

void	ft_bresen_neg_low(t_data *data, t_point point0, t_point point1)
{
	int	d[3];
	int	coord[2];

	d[0] = point1.x_mod - point0.x_mod;
	d[1] = point1.y_mod - point0.y_mod;
	coord[0] = point0.x_mod;
	coord[1] = point0.y_mod;
	d[2] = 2 * d[1] - d[0];
	while (coord[0] < point1.x_mod)
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

void	ft_bresen_neg_high(t_data *data, t_point point0, t_point point1)
{
	int	d[3];
	int	coord[2];

	d[0] = point1.x_mod - point0.x_mod;
	d[1] = point1.y_mod - point0.y_mod;
	coord[0] = point1.x_mod;
	coord[1] = point1.y_mod;
	d[2] = 2 * d[1] - d[0];
	while (coord[1] < point0.y_mod)
	{
		if (d[2] >= 0)
		{
			my_mlx_pixel_put(data, coord[0], coord[1], 0x00FFFFFF);
			coord[0]--;
			d[2] = d[2] + 2 * d[0] + 2 * d[1];
		}
		else
		{
			my_mlx_pixel_put(data, coord[0], coord[1], 0x00FFFFFF);
			d[2] = d[2] + 2 * d[0];
		}
		coord[1]++;
	}
}
