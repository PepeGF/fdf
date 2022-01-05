#include "fdf.h"

//#include "/usr/include/X11/keysym.h"
#define MLX_ERROR 1
#define WIN_WIDTH 800
#define WIN_HEIGHT 600
//	%s///usleep/\/\///usleep/g
//	%s/\/\///usleep///usleep/g

int	handle_no_event(void *data)
{
	(void)data;
	return (0);
}

int	handle_input(int keysum, t_data *data)
{
	if (keysum == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Testing things");
	if (data.win_ptr == NULL)
	{
		free(data.mlx_ptr);
		return (MLX_ERROR);
	}
	usleep(10000);
	mlx_pixel_put(data.mlx_ptr, data.win_ptr, WIN_WIDTH/2, WIN_HEIGHT/2, 0xffffff);
	int i = 1;
	while (i <= 240)
	{
	usleep(10);
	mlx_pixel_put(data.mlx_ptr, data.win_ptr, WIN_WIDTH/2+i, WIN_HEIGHT/2+i, 0x0000ff);
	mlx_pixel_put(data.mlx_ptr, data.win_ptr, WIN_WIDTH/2-i, WIN_HEIGHT/2+i, 0x00ff00);
	mlx_pixel_put(data.mlx_ptr, data.win_ptr, WIN_WIDTH/2+i, WIN_HEIGHT/2-i, 0xff0000);
	mlx_pixel_put(data.mlx_ptr, data.win_ptr, WIN_WIDTH/2-i, WIN_HEIGHT/2-i, 0xff00ff);
	i += 1;
	}
	/* Setup hooks */
	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_key_hook(data.win_ptr, &handle_input, &data);

	mlx_loop(data.mlx_ptr);

/*	Si se deja esta línea se produce un bus error  */
//	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}

int	rgb_to_int(double r, double g, double b)
{
	int	color;

	color = 0;
	color |= (int)(r * 255);
	color |= (int)(g * 255) << 8;
	color |= (int)(b * 255) << 16;
	return (color);
}
