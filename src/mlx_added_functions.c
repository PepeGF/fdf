/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_added_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:53:29 by josgarci          #+#    #+#             */
/*   Updated: 2022/04/14 10:56:22 by josgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/*
 * This function is the drawing key. 
 * It writes the info of each pixel into the image before put the image in
 * the window.
 */
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/*
 * To control what happens if ESC or Q is pressed.
 */
int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53 || keycode == 12)
	{
		mlx_clear_window(data->mlx_ptr, data->mlx_win);
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		exit (0);
	}
	return (0);
}
