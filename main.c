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
	(void)data;
	if (keysum == 53/*XK_Escape*/)
	{exit(0);}
//		mlx_destroy_image/*window*/(data->mlx_ptr, data->win_ptr);
	return (0);
}

void	like_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "Wololo");
	img.img = mlx_new_image(mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);
	like_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
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
