#include "./mlx_linux/mlx.h"
#include <stdio.h>

int	main(void)
{
	void	*mlx;
	mlx = mlx_init();
	printf("%p\n", mlx);

	return (0);
}
