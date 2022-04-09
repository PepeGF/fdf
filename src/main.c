#include "../inc/fdf.h"

void	leakss()
{
	system ("leaks fdf");
}

int	main(int argc, char *argv[])
{
	t_list		*raw_map;
	t_point		**points;
	t_coord		map_size;
	t_data		data;

// atexit(leakss);
	if (argc != 2)
		return (33);
	raw_map = NULL;
	printf("%d\t%d\n", WIN_WIDTH*1, WIN_HEIGHT*1);
	//funcion para inicializar data en cero???
	ft_map_read(&raw_map, argv[1]);
	map_size.x = ft_map_length(raw_map->content);
	map_size.y = ft_lstsize(raw_map);
	ft_map_create_array(&points, map_size);
	ft_map_int_array(raw_map, points);
	ft_map_raw_free(raw_map);
	ft_convert_points_2d(points, map_size);

	ft_map_middle_x(points, map_size, &data);
	ft_map_middle_y(points, map_size, &data);
	ft_get_scale(&data);


	data.mlx_ptr = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "FDF");
	data.img = mlx_new_image(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_lenght, &data.endian);
	
	ft_adapt_points_to_screen(points, &data, map_size);
	ft_print_points(points, map_size);
	ft_triangle(&data, points, map_size);
	ft_draw_vertex(points, &data, map_size);
	//system ("leaks fdf");
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.img, 0, 0);
	mlx_key_hook(data.mlx_win, &key_hook, &data);
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

/*	
	points[0][0].x = WIN_WIDTH / 2;
	points[0][0].y = WIN_HEIGHT / 2;
	points[1][1].x = WIN_WIDTH / 2 + 100;
	points[1][1].y = 100;
	points[2][2].x = WIN_WIDTH - 100;
	points[2][2].y = WIN_HEIGHT / 2 - 100;
	points[3][3].x = WIN_WIDTH - 100;
	points[3][3].y = WIN_HEIGHT / 2 + 100;
	points[4][4].x = WIN_WIDTH / 2 + 100;
	points[4][4].y = WIN_HEIGHT - 100;
	points[5][5].x = WIN_WIDTH / 2 - 100;
	points[5][5].y = 100;
	points[6][6].x = 100;
	points[6][6].y = WIN_HEIGHT / 2 - 100;
	points[7][7].x = 100;
	points[7][7].y = WIN_HEIGHT / 2 + 100;
	points[8][8].x = WIN_WIDTH / 2 - 100;
	points[8][8].y = WIN_HEIGHT - 100;
	ft_decide_line(&data, points[0][0], points[1][1]);
	ft_decide_line(&data, points[0][0], points[2][2]);
	ft_decide_line(&data, points[0][0], points[3][3]);
	ft_decide_line(&data, points[0][0], points[4][4]);
	ft_decide_line(&data, points[0][0], points[5][5]);
	ft_decide_line(&data, points[0][0], points[6][6]);
	ft_decide_line(&data, points[0][0], points[7][7]);
	ft_decide_line(&data, points[0][0], points[8][8]);
	my_mlx_pixel_put(&data, points[0][0].x, points[0][0].y, 0xff0000);
	my_mlx_pixel_put(&data, points[1][1].x, points[1][1].y, 0xff0000);
	my_mlx_pixel_put(&data, points[2][2].x, points[2][2].y, 0xff0000);
	my_mlx_pixel_put(&data, points[3][3].x, points[3][3].y, 0xff0000);
	my_mlx_pixel_put(&data, points[4][4].x, points[4][4].y, 0xff0000);
	my_mlx_pixel_put(&data, points[5][5].x, points[5][5].y, 0xff0000);
	my_mlx_pixel_put(&data, points[6][6].x, points[6][6].y, 0xff0000);
	my_mlx_pixel_put(&data, points[7][7].x, points[7][7].y, 0xff0000);
	my_mlx_pixel_put(&data, points[8][8].x, points[8][8].y, 0xff0000);
*/
