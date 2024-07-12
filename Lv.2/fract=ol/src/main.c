/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:04:46 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/05/07 21:12:49 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../inc/fractol.h"

t_fractol	check_arg(int n, char **ag)
{
	t_fractol	fractol;

	if (n == 2 && !(ft_strncmp(ag[1], "j", 2)))
		fractol.type = 'j';
	else if (n == 2 && !(ft_strncmp(ag[1], "m", 2)))
		fractol.type = 'm';
	else if (n == 2 && !(ft_strncmp(ag[1], "b", 2)))
		fractol.type = 'b';
	else if (n == 2 && !(ft_strncmp(ag[1], "M", 2)))
		fractol.type = 'M';
	else if (n == 2 && !(ft_strncmp(ag[1], "p", 2)))
		fractol.type = 'p';
	else
	{
		ft_putstr("input ./fractol <type>");
		ft_putstr("type: b m j M p");
		exit(0);
	}
	fractol.cenetrx = 0;
	fractol.centery = 0;
	fractol.zoom = 1;
	fractol.coler = 0;
	return (fractol);
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	fractol = check_arg(argc, argv);
	drow_fractal(fractol);
	return (0);
}

//Julila j
//Mandelbrot m
//Burning ship b
//Mandelbar M
//Perpendicular burning ship p