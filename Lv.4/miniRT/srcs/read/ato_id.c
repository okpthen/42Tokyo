/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ato_id.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:44:00 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/06/14 12:32:35 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/read.h"

double	ft_atod_sub(char *str, long num, int i, int dot)
{
	double	result;

	while (ft_isdigit(*str))
	{
		num = (*str - '0') + num * 10;
		str ++;
	}
	if (*str == '.')
	{
		str ++;
		while (ft_isdigit(*str))
		{
			num = (*str - '0') + num * 10;
			str ++;
			dot ++;
		}
		result = num * pow(0.1, dot) * i;
		return (result);
	}
	result = num * i;
	return (result);
}

double	ft_atod(char	*str)
{
	long	num;
	int		i;
	int		dot;

	i = 1;
	dot = 0;
	num = 0;
	if (*str == '-')
	{
		str ++;
		i = -i ;
	}
	return (ft_atod_sub(str, num, i, dot));
}

bool	check_double(char *str)
{
	int	i;

	i = 0;
	if (*str == '-')
		str ++;
	while (ft_isdigit(*str) || *str == '.')
	{
		if (*str == '.')
			i ++;
		str ++;
	}
	if (i < 2 && (*str == '\0' || *str == '\n'))
		return (true);
	else
		return (false);
}

int	ato_color(char	*str)
{
	int	i;

	i = 0;
	while (*str && *str != '\n')
	{
		i = (*str - '0') + i * 10;
		if (i < 0 || 255 < i || !ft_isdigit(*str))
			return (COLER_ERROR);
		str ++;
	}
	return (i);
}

int	ato_fov(char	*str)
{
	int	i;

	i = 0;
	while (*str && *str != '\n')
	{
		i = (*str - '0') + i * 10;
		if (i < 0 || 180 < i || !ft_isdigit(*str))
			return (FOV_ERROR);
		str ++;
	}
	return (i);
}
