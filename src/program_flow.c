/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_flow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:53:46 by josgarci          #+#    #+#             */
/*   Updated: 2022/04/14 11:08:40 by josgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/*
 * Workflow of the first part of the program.
 * After map reading prepares the struct matrix, frees the lines list,
 * makes some math to convert 3D to 2D, gets the center of the drawing and
 * calculates how big the image must be.
 */
void	ft_map_functions(t_list *raw_map, t_point **points, t_coord map_size,
		t_data *data)
{
	ft_map_int_array(raw_map, points);
	ft_map_raw_free(raw_map);
	ft_convert_points_2d(points, map_size);
	ft_map_middle_x(points, map_size, data);
	ft_map_middle_y(points, map_size, data);
	ft_get_scale(data);
}

/*
 * Prepares mlx_lib pointers.
 */
void	ft_set_data(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
	{
		perror("Unable to create mlx pointer\n");
		exit(2);
	}
	data->mlx_win = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "FDF");
	if (data->mlx_win == NULL)
	{
		perror("Unable to create window pointer\n");
		exit(2);
	}
	data->img = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &(data->bits_per_pixel),
			&(data->line_lenght), &(data->endian));
}

/*
 * Calls drawing functions.
 */
void	ft_drawing(t_point **points, t_data *data, t_coord map_size)
{
	ft_adapt_pts_screen(points, data, map_size);
	ft_triangle(data, points, map_size);
	ft_draw_vertex(points, data, map_size);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, 0, 0);
	mlx_key_hook(data->mlx_win, &key_hook, data);
	mlx_loop(data->mlx_ptr);
}
