/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:54:36 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/27 13:16:01 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_freeall(int **board, struct s_map map)
{
	int	y;

	y = 0;
	while (y < map.y)
	{
		free(board[y]);
		y ++;
	}
	free(board);
}
