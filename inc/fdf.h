/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:42:38 by josgarci          #+#    #+#             */
/*   Updated: 2022/04/10 11:43:57 by josgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define MLX_ERROR 1
# define WIN_WIDTH 1200
# define WIN_HEIGHT 750

//# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"

/* ni idea de para que usar esta estructura, creo que es para algo de minilib*/
typedef struct s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
	int		offset;
	int		map_center_x;
	int		map_center_y;
	int		map_dimension_x;
	int		map_dimension_y;
	double	scale;
}	t_data;

/* Estructura para almacenar colores */
typedef struct s_colors
{
	int				r;
	int				g;
	int				b;
	unsigned int	rgb;
}	t_colors;

/* estructura para almacenar coordenadas */
//ni idea de para cuando y xq
//parece que para el mapa
typedef struct s_coord
{
	int			x;
	int			y;
	int			z;
}	t_coord;

/* Estructura para listas de puntos con coordenadas y color */
typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	int				x_mod;
	int				y_mod;
	int				z_mod;
	unsigned int	color;
}	t_point;

typedef struct s_bresenham
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	p;
	int	m;
}	t_bresen;

/* Manage map functions*/
void	ft_map_read(t_list **raw_map, char *file);
void	ft_map_raw_free(t_list *raw_map);
void	ft_map_int_array(t_list *raw_map, t_point **points);
int		ft_map_length(char *line);
void	ft_map_free_array(t_point **points, t_coord map_size);
void	ft_map_create_array(t_point ***points, t_coord map_size);

/* PENDIENTE DE CLASIFICACIÓN */
/* Funciones testadas y operativas */

void	ft_print_points(t_point **points, t_coord map_size);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		key_hook(int keycode, t_data *data);
void	ft_convert_points_2d(t_point **points, t_coord map_size);
void	ft_adapt_pts_screen(t_point **points, t_data *data, t_coord map_size);
void	ft_draw_vertex(t_point **points, t_data *data, t_coord map_size);
void	ft_map_middle_x(t_point **points, t_coord map_size, t_data *data);
void	ft_map_middle_y(t_point **points, t_coord map_size, t_data *data);
void	ft_get_scale(t_data *data);

void	ft_bresen_neg_low(t_data *data, t_point point0, t_point point1);
void	ft_bresen_pos_low(t_data *data, t_point point0, t_point point1);
void	ft_bresen_pos_high(t_data *data, t_point point0, t_point point1);
void	ft_bresen_neg_high(t_data *data, t_point point0, t_point point1);
void	ft_decide_line(t_data *data, t_point point0, t_point point1);
void	ft_triangle(t_data *data, t_point **points, t_coord map_size);

#endif 
