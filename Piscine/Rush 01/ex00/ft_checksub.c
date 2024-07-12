/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checksub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 01:41:00 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/18 10:46:38 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	up_down(int *hint, int *map, int point)
{
	int	count;
	int	i;
	int	high;

	high = 0;
	i = 0;
	count = 0;
	if (Y != 3)
		return (1);
	while (i < 4)
	{
		if (map[X +(4 * i)] > high)
		{
			count ++;
			high = map[X +(4 * i)];
		}
		i ++;
	}
	if (hint[X] == count)
		return (1);
	return (0);
}

int	down_up(int *hint, int *map, int point)
{
	int	count;
	int	i;
	int	high;

	high = 0;
	i = 3;
	count = 0;
	if (Y != 3)
		return (1);
	while (-1 < i)
	{
		if (map[X +(4 * i)] > high)
		{
			count ++;
			high = map[X +(4 * i)];
		}
		i --;
	}
	if (hint[X + 4] == count)
		return (1);
	return (0);
}

int	left_right(int *hint, int *map, int point)
{
	int	count;
	int	i;
	int	high;

	high = 0;
	i = 0;
	count = 0;
	if (X != 3)
		return (1);
	while (i < 4)
	{
		if (map[(4 * Y) + i] > high)
		{
			count ++;
			high = map[(4 * Y) + i];
		}
		i ++;
	}
	if (hint[Y + 8] == count)
		return (1);
	return (0);
}

int	right_left(int *hint, int *map, int point)
{
	int	count;
	int	i;
	int	high;

	high = 0;
	i = 3;
	count = 0;
	if (X != 3)
		return (1);
	while (i > -1)
	{
		if (map[(4 * Y) + i] > high)
		{
			count ++;
			high = map[(4 * Y) + i];
		}
		i --;
	}
	if (hint[Y +12] == count)
		return (1);
	return (0);
}
