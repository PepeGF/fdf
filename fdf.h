/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:42:38 by josgarci          #+#    #+#             */
/*   Updated: 2022/03/08 21:05:47 by josgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
// Linux
# include <X11/keysym.h>
# include "./mlx_linux/mlx.h"
// Mac
// # include <mlx.h>
# include "./gnl/get_next_line.h"
# include "./libft/libft.h"

/* ni idea de para que usar esta estructura, creo que es para algo de minilib*/
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}	t_data;

/* Estructura para almacenar colores */
typedef struct s_colors
{
	int				r;
	int				g;
	int				b;
	unsigned int	rgb;
}	t_colors;

/* estructura para almacenar coordenadas y color */
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
	int					x;
	int					y;
	int					z;
	unsigned int		color;
	struct s_point		*next;
}	t_point;

/* Estructura para ventanas, pero no me acuerdo */
typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

int		ft_map_length(char *line);
void	ft_save_map(t_list **raw_map, char *file);
void	ft_free_map(t_list *raw_map);
#endif 
