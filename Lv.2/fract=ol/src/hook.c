/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:02:39 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/05/07 21:12:48 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../inc/fractol.h"
#include <stdio.h>

int	window_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	zoom_in_out(keycode, vars);
	updown_rightleft(keycode, vars);
	return (0);
}

int	mouse_down(int key, int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	(void)vars;
	if (key == 4)
	{
		vars->fra.zoom *= 2;
		drow(*vars);
	}	
	if (key == 5)
	{
		vars->fra.zoom *= 0.5;
		drow(*vars);
	}
	return (0);
}
