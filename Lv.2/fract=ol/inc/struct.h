/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:44:28 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/05/07 20:13:57 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum
{
	UP = 13,
	DOWN = 1,
	RIGHT = 2,
	LEFT = 0,
	SPACE = 49,
	ZOOMIN = 24,
	ZOOMOUT = 27,
	ESC = 53
};

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_fractol
{
	char	type;
	double	cimag;
	double	creal;
	double	zimag;
	double	zreal;
	double	cenetrx;
	double	centery;
	double	zoom;
	int		coler;
}	t_fractol;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_data		img;
	t_fractol	fra;
}				t_vars;

typedef struct c_coler
{
	double	h;
	double	s;
	double	l;
	double	c;
	double	x;
	double	m;
	double	r;
	double	g;
	double	b;
}	t_coler;

#endif