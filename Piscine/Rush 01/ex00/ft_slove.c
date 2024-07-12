/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slove.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 00:31:18 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/18 10:46:25 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	map_clear(int *map, int i)
{
	while (i < 16)
	{
		map[i] = -1;
		i ++;
	}
	return ;
}

void	ft_slove(int *hint, int *map, int point, int *flag)
{
	int	high;

	high = 1;
	while (5 > high)
	{
		map[point] = high;
		map_clear(map, point +1);
		if (ft_check(hint, map, point) == 1)
		{
			if (point == 15)
			{
				ft_print(map, *flag);
				*flag = 1;
			}
			else
			{
				ft_slove(hint, map, point + 1, flag);
			}
		}
		high ++;
	}
	return ;
}
