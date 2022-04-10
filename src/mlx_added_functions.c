#include "../inc/fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53 || keycode == 12)
	{
		mlx_clear_window(data->mlx_ptr, data->mlx_win);
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		exit (0);
	}
}
