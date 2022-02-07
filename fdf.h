/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josgarci <josgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:42:38 by josgarci          #+#    #+#             */
/*   Updated: 2022/01/17 20:10:49 by josgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <X11/keysym.h>
# include "./mlx_linux/mlx.h"
// # include <mlx.h>
# include "./gnl/get_next_line.h"
# include "./libft/libft.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}	t_data;

typedef struct s_colors
{
	int				r;
	int				g;
	int				b;
	unsigned int	rgb;
}	t_colors;

typedef struct s_coords
{
	int			x;
	int			y;
	int			z;
	t_colors	colors;
}	t_coords;

typedef struct s_point
{
	int					x;
	int					y;
	int					z;
	unsigned int		color;
	struct s_point		*next;
}	t_point;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

#endif 
