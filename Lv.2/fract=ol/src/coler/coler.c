/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coler.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:18:59 by kazokada          #+#    #+#             */
/*   Updated: 2024/05/07 20:42:07 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

void	clsrgb1(t_coler *cl)
{
	if (cl->h >= 0 && cl->h < 60)
	{
		cl->r = cl->c;
		cl->g = cl->x;
		cl->b = 0;
	}
	else if (cl->h >= 60 && cl->h < 120)
	{
		cl->r = cl->x;
		cl->g = cl->c;
		cl->b = 0;
	}
	else if (cl->h >= 120 && cl->h < 180)
	{
		cl->r = 0;
		cl->g = cl->c;
		cl->b = cl->x;
	}
}

void	clsrgb2(t_coler *cl)
{
	if (cl->h >= 180 && cl->h < 240)
	{
		cl->r = 0;
		cl->g = cl->x;
		cl->b = cl->c;
	}
	else if (cl->h >= 240 && cl->h < 300)
	{
		cl->r = cl->x;
		cl->g = 0;
		cl->b = cl->c;
	}
	else if (cl->h >= 300 && cl->h < 360)
	{
		cl->r = cl->c;
		cl->g = 0;
		cl->b = cl->x;
	}	
}

int	hlstorgb(int h)
{
	t_coler	cl;
	int		red;
	int		green;
	int		blue;

	if (h == 0 || h == 100)
		return (0);
	cl.h = fmod(h * 3.6, 360);
	cl.s = 0.5;
	cl.l = 0.5;
	cl.c = (1 - fabs(2 * cl.l - 1)) * cl.s;
	cl.x = cl.c * (1 - fabs(fmod(h / 60.0, 2) - 1));
	cl.m = cl.l - cl.c / 2.0;
	clsrgb1(&cl);
	clsrgb2(&cl);
	red = (cl.r + cl.m) * 255;
	green = (cl.g + cl.m) * 255;
	blue = (cl.b + cl.m) * 255;
	return ((red << 16) + (green << 8) + blue);
}

// int main()
// {
// 	int	coler;

// 	coler = hlstorgb(1);
// 	printf("%d %x\n", coler, coler);
// }