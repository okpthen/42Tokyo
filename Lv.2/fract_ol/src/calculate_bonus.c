/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 23:16:19 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/05/07 21:12:30 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	recursion_burning(t_fractol fra)
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
		fra.zimag = 2 * fabs(pzr * fra.zimag) + fra.cimag;
		if (pzi == fra.zimag && pzr == fra.zreal)
			return (0);
	}
	return (0);
}

int	type_burning(t_fractol fra, int x, int y)
{
	fra.creal = (x - WIDTH / 2);
	fra.creal = ((fra.creal * 4) / (WIDTH * fra.zoom)) + fra.cenetrx;
	fra.cimag = (y - WIDTH / 2);
	fra.cimag = ((fra.cimag * 4) / (WIDTH * fra.zoom)) + fra.centery;
	fra.zimag = 0;
	fra.zreal = 0;
	return (recursion_burning(fra));
}

int	recursion_mandelbar(t_fractol fra)
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
		fra.zimag = -2 * pzr * fra.zimag + fra.cimag;
		if (pzi == fra.zimag && pzr == fra.zreal)
			return (0);
	}
	return (0);
}

int	type_mandelbar(t_fractol fra, int x, int y)
{
	fra.creal = (x - WIDTH / 2);
	fra.creal = ((fra.creal * 4) / (WIDTH * fra.zoom)) + fra.cenetrx;
	fra.cimag = (y - WIDTH / 2);
	fra.cimag = ((fra.cimag * 4) / (WIDTH * fra.zoom)) + fra.centery;
	fra.zimag = 0;
	fra.zreal = 0;
	return (recursion_mandelbar(fra));
}
