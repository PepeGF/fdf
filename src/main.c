#include "../inc/fdf.h"

#define MLX_ERROR 1
#define WIN_WIDTH 800
#define WIN_HEIGHT 600
void	leakss()
{
	system ("leaks fdf");
}


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
	write(1, "WOLOLO\n", 7);
}





int	main(int argc, char *argv[])
{
	t_list		*raw_map;
	t_point		**points;
	t_coord		map_size;
	t_data		data;

	//atexit(leakss);
	if (argc != 2)
		return (33);
	raw_map = NULL;
	ft_map_read(&raw_map, argv[1]);
	map_size.x = ft_map_length(raw_map->content);
	map_size.y = ft_lstsize(raw_map);
	ft_map_create_array(&points, map_size);
	ft_map_int_array(raw_map, points);
	ft_map_raw_free(raw_map);

	data.mlx_ptr = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx_ptr, 1920, 1080, "Wololo!");
	data.img = mlx_new_image(data.mlx_ptr, 1920, 1080);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_lenght, &data.endian);
	printf("-----%d , %d , %d ------\n",data.bits_per_pixel, data.line_lenght, data.endian);
	my_mlx_pixel_put(data.img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.img, 0, 0);
	//sleep(5);
	system("leaks fdf");
	mlx_loop(data.mlx_ptr);

	ft_map_free_array(points, map_size);
	return (0);
}

int	rgb_to_int(int r, int g, int b)
{
	int	color;

	color = 0;
	color += (r << 16);
	color += (g << 8);
	color += b;
	return (color);
}
