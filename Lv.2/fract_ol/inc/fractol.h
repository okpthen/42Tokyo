/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:28:10 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/05/07 21:18:33 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include "struct.h"
# include "coler.h"
# include <unistd.h>
# include <math.h>

# define WIDTH 400
# define CREAL -0.3
# define CIMAG -0.63
# define TIME 50

void		ft_putstr(char *str);
int			ft_strncmp(const char *s1, const char *s2, unsigned int max);
void		drow_fractal(t_fractol fra);
int			window_close(t_vars *vars);
int			key_hook(int keycode, t_vars *vars);
int			calculate_divergence(t_fractol fra, int x, int y);
void		drow(t_vars vars);
int			type_burning(t_fractol fra, int x, int y);
int			type_mandelbar(t_fractol fra, int x, int y);
int			type_perpendicular(t_fractol fra, int x, int y);
int			hlstorgb(int h);
int			mouse_down(int key, int x, int y, t_vars *vars);
void		zoom_in_out(int keycode, t_vars *vars);
void		updown_rightleft(int keycode, t_vars *vars);

#endif