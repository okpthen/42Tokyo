/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:59:51 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/28 12:49:54 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

// struct s_map	ft_fullobstacle(struct s_map map, char *str)
// {
// 	if (map.x >= map.y)
// 		map.biggest = map.y;
// 	else
// 		map.biggest = map.x;
// 	while (*str != '\n')
// 		str ++;
// 	str ++;
// 	while (*str)
// 	{
// 		if (*str == map.empty)
// 			return (map);
// 		str ++;
// 	}
// 	map.check = 0;
// 	return (map);
// }

struct s_map	ft_printable(struct s_map map, char *str)
{
	while (*str)
	{
		if (!((*str <= 126 && *str >= 32) || *str == '\n'))
			map.check = 0;
		str ++;
	}
	if (map.x == 0)
		map.check = 0;
	return (map);
}
