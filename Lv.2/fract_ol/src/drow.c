/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:54:10 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/05/07 21:12:46 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../inc/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	drow(t_vars vars)
{
	int	x;
	int	y;
	int	coler;

	y = 0;
	while (y < WIDTH)
	{
		x = 0;
		while (x < WIDTH)
		{
			coler = calculate_divergence(vars.fra, x, y);
			if (coler != 0)
				coler = hlstorgb(coler + vars.fra.coler);
			my_mlx_pixel_put(&vars.img, x, y, coler);
			x ++;
		}
		y ++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
}

void	drow_fractal(t_fractol fra)
{
	t_vars	vars;

	vars.fra = fra;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, WIDTH, "fractol");
	vars.img.img = mlx_new_image(vars.mlx, WIDTH, WIDTH);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel,
			&vars.img.line_length, &vars.img.endian);
	drow(vars);
	mlx_hook(vars.win, ON_DESTROY, 0, window_close, &vars);
	mlx_hook(vars.win, ON_MOUSEDOWN, 0, mouse_down, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}
