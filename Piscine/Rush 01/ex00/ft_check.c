/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 01:03:58 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/18 10:46:43 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	check_same(int *map, int point)
{
	int	i;

	i = 0;
	if (map[point] == -1)
		return (1);
	while (i < 4)
	{
		if ((map[(4 * i) + X] == map[point]) && ((4 * i) + X) != point)
			return (0);
		i ++;
	}
	i = 0;
	while (i < 4)
	{
		if ((map[(Y * 4) + i] == map[point]) && ((Y * 4) + i) != point)
			return (0);
		i ++;
	}
	return (1);
}

int	ft_check(int *hint, int *map, int point)
{
	if (up_down(hint, map, point) == 0)
		return (0);
	if (down_up(hint, map, point) == 0)
		return (0);
	if (right_left(hint, map, point) == 0)
		return (0);
	if (left_right(hint, map, point) == 0)
		return (0);
	if (check_same(map, point) == 0)
		return (0);
	return (1);
}

// printf ("%d %d %d %d %d \n",up_down(hint, map, point), 
// 	down_up(hint, map, point),right_left(hint, map, point), 
// 	left_right(hint, map, point), check_same(map, point));
// printf ("x=%d y=%d point=%d \n\n",X, Y, point);