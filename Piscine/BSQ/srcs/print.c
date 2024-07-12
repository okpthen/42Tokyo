/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:08:48 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/27 12:19:57 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_print(int **board, struct s_map map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map.y)
	{
		x = 0;
		while (x < map.x)
		{
			if (board[y][x] == 1)
				ft_putchar(map.full);
			if (board[y][x] == 2)
				ft_putchar(map.empty);
			if (board[y][x] == 0)
				ft_putchar(map.obstacle);
			x ++;
		}
		ft_putchar('\n');
		y ++;
	}
}
