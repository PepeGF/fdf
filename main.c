#include "fdf.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1300, 880, "Que pasa neeeen!");
	(void)mlx_win;
	mlx_loop(mlx);
	return (0);
}