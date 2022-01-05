#include "fdf.h"
#include <unistd.h>
//	%s/usleep/\/\/usleep/g
//	%s/\/\/usleep/usleep/g

int	main(void)
{
	void	*mlx;
	void	*win;


	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "Testing things");
	usleep(1000);
	//mlx_pixel_put(mlx, win, 500/2, 500/2, 0xffffff);
	int i = 0;
	char aux = 65;
	while (++i <= 50)
	{
	usleep(10000);
//		write (1, &aux, 1);
	usleep(10000);
	mlx_pixel_put(mlx, win, 500/2+i, 500/2+i, 0xffffff);
	usleep(10000);
	mlx_pixel_put(mlx, win, 500/2-i, 500/2+i, 0xffffff);
	usleep(10000);
	mlx_pixel_put(mlx, win, 500/2+i, 500/2-i, 0xffffff);
	usleep(10000);
	mlx_pixel_put(mlx, win, 500/2-i, 500/2-i, 0xffffff);
	usleep(10000);
	mlx_pixel_put(mlx, win, 500/2, 500/2+i, 0xffffff);
	usleep(10000);
	mlx_pixel_put(mlx, win, 500/2-i, 500/2, 0xffffff);
	usleep(10000);
	mlx_pixel_put(mlx, win, 500/2+i, 500/2, 0xffffff);
	usleep(10000);
	mlx_pixel_put(mlx, win, 500/2, 500/2-i, 0xffffff);
	usleep(10000);
	aux++;
	if (aux == 90)
		aux = 65;
	}
	mlx_loop(mlx);
	return (0);
}

//	t_data	img;
//	img.img = mlx_new_image(mlx, 1300,800);
//	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
int	rgb_to_int(double r, double g, double b)
{
	int	color;

	color = 0;
	color |= (int)(r * 255);
	color |= (int)(g * 255) << 8;
	color |= (int)(b * 255) << 16;
	return (color);
}
