/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 22:45:21 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/18 17:06:17 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	ft_mapset(int *map)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		map[i] = -1;
		i ++;
	}
	return ;
}

void	ft_rush(char *str, int *map)
{
	int	*hint;
	int	flag;

	flag = 0;
	hint = malloc(16 * 4);
	if (hint == NULL)
		return ;
	if (input_check(str))
	{
		ft_gethint(hint, str);
		ft_slove(hint, map, 0, &flag);
		if (flag == 0)
			ft_putstr("Error\n");
	}
	else
	{
		ft_putstr("Error\n");
	}
	free(hint);
}

int	main(int argc, char **argv)
{
	int	*map;

	if (argc != 2)
	{
		ft_putstr("Error\n");
		return (0);
	}
	map = malloc (16 * 4);
	if (map == NULL)
		return (0);
	ft_mapset(map);
	ft_rush(argv[1], map);
	free(map);
	return (0);
}
