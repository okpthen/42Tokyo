/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcutate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:33:55 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/05/07 21:12:44 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	recursion_formula(t_fractol fra)
{
	double	pzr;
	double	pzi;
	int		i;

	i = 0;
	while (i < TIME)
	{
		i ++;
		pzi = fra.zimag;
		pzr = fra.zreal;
		if (pow(fra.zreal, 2) + pow(fra.zimag, 2) > 4)
			return (i);
		fra.zreal = pow(fra.zreal, 2) - pow(fra.zimag, 2) + fra.creal;
		fra.zimag = 2 * pzr * fra.zimag + fra.cimag;
		if (pzi == fra.zimag && pzr == fra.zreal)
			return (0);
	}
	return (0);
}

int	type_julia(t_fractol fra, int x, int y)
{
	fra.cimag = CIMAG;
	fra.creal = CREAL;
	fra.zreal = (x - WIDTH / 2);
	fra.zreal = (((fra.zreal * 4) / (WIDTH * fra.zoom)) + fra.cenetrx);
	fra.zimag = (y - WIDTH / 2);
	fra.zimag = (((fra.zimag * 4) / (WIDTH * fra.zoom)) + fra.centery);
	return (recursion_formula(fra));
}

int	type_mandelbrot(t_fractol fra, int x, int y)
{
	fra.creal = (x - WIDTH / 2);
	fra.creal = ((fra.creal * 4) / (WIDTH * fra.zoom)) + fra.cenetrx;
	fra.cimag = (y - WIDTH / 2);
	fra.cimag = ((fra.cimag * 4) / (WIDTH * fra.zoom)) + fra.centery;
	fra.zimag = 0;
	fra.zreal = 0;
	return (recursion_formula(fra));
}

int	calculate_divergence(t_fractol fra, int x, int y)
{
	if (fra.type == 'j')
		return (type_julia(fra, x, y));
	else if (fra.type == 'm')
		return (type_mandelbrot(fra, x, y));
	else if (fra.type == 'b')
		return (type_burning(fra, x, y));
	else if (fra.type == 'M')
		return (type_mandelbar(fra, x, y));
	else if (fra.type == 'p')
		return (type_perpendicular(fra, x, y));
	return (0);
}
