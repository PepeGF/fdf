#include "fdf.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;


	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1280, 720, "Que pasa neeeen!");
	img.img = mlx_new_image(mlx, 1300,800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mlx_loop(mlx);
	return (0);
}
