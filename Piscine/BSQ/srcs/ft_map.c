/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:34:14 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/28 21:36:40 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

struct s_map	ft_getmap(char *str, t_map map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	map.y = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i ++;
	if (i < 4)
	{
		map.check = 0;
		return (map);
	}
	map.empty = str[i - 3];
	map.full = str[i - 1];
	map.obstacle = str[i - 2];
	while (j < (i - 3))
	{
		map.y = map.y * 10 + (str[j] - '0');
		j ++;
	}
	return (map);
}

struct s_map	ft_samechar(struct s_map map, char *str)
{
	int	i;

	i = 0;
	if (map.empty == map.full || map.empty == map.obstacle)
		map.check = 0;
	if (map.full == map.obstacle)
		map.check = 0;
	while (*str != '\n' && *str)
		str ++;
	if (*str == '\0')
	{
		map.check = 0;
		return (map);
	}
	str ++;
	while (*str != '\n' && *str)
	{
		if (*str != map.obstacle && *str != map.empty)
			map.check = 0;
		str ++;
		i ++;
	}
	map.x = i;
	return (map);
}

struct s_map	ft_final(struct s_map map, char *str)
{
	int	cx;
	int	cy;

	cy = 1;
	while (*str)
	{
		cx = 0;
		while (*str != '\n' && *str)
		{
			if (*str != map.obstacle && *str != map.empty)
				map.check = 0;
			cx ++;
			str ++;
		}
		if (map.x != cx)
			map.check = 0;
		if (!*str)
			break ;
		str ++;
		cy ++;
	}
	if (map.y != cy)
		map.check = 0;
	return (map);
}

struct s_map	ft_mapcheck(struct s_map map, char *str)
{
	t_map	mapcopy;

	while (*str != '\n' && *str)
		str ++;
	if (!*str)
	{
		map.check = 0;
		return (map);
	}
	str ++;
	while (*str != '\n' && *str)
		str ++;
	if (!*str)
	{
		map.check = 0;
		return (map);
	}
	str ++;
	mapcopy = ft_final(map, str);
	return (mapcopy);
}

struct s_map	ft_map(char *str)
{
	t_map	map;

	if (*str == '\0')
	{
		map.check = 0;
		return (map);
	}
	map.check = 1;
	map = ft_getmap(str, map);
	map = ft_samechar(map, str);
	map = ft_mapcheck(map, str);
	map = ft_printable(map, str);
	return (map);
}
