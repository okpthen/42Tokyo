/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 20:03:43 by kazokada          #+#    #+#             */
/*   Updated: 2024/05/07 21:12:51 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../inc/fractol.h"

void	zoom_in_out(int keycode, t_vars *vars)
{
	if (keycode == ESC)
		window_close(vars);
	if (keycode == ZOOMIN)
	{
		vars->fra.zoom *= 2;
		drow(*vars);
	}
	if (keycode == ZOOMOUT)
	{
		vars->fra.zoom *= 0.5;
		drow(*vars);
	}
	if (keycode == SPACE)
	{
		vars->fra.coler += 120;
		drow(*vars);
	}
}

void	updown_rightleft(int keycode, t_vars *vars)
{
	if (keycode == UP)
	{
		vars->fra.centery -= (0.8 / vars->fra.zoom);
		drow(*vars);
	}
	if (keycode == DOWN)
	{
		vars->fra.centery += (0.8 / vars->fra.zoom);
		drow(*vars);
	}
	if (keycode == RIGHT)
	{
		vars->fra.cenetrx += (0.8 / vars->fra.zoom);
		drow(*vars);
	}
	if (keycode == LEFT)
	{
		vars->fra.cenetrx -= (0.8 / vars->fra.zoom);
		drow(*vars);
	}
}
