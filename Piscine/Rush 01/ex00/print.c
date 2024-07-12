/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 03:42:29 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/18 13:47:59 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	ft_print(int *map, int flag)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	if (flag)
		return ;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = map[(4 * i) + j] + '0';
			ft_putchar(c);
			if (j != 3)
				ft_putchar(' ');
			j ++;
		}
		ft_putchar('\n');
		i ++;
	}
}
