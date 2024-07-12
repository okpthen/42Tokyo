/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:04:58 by kazokada          #+#    #+#             */
/*   Updated: 2024/04/17 16:45:39 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <limits.h>

long	ft_max(int s)
{
	if (s == 1)
		return (LONG_MAX);
	if (s == -1)
		return (LONG_MIN);
	return (0);
}

int	ft_long(long num, long c)
{
	if (num == 0)
		return (0);
	if ((LONG_MAX - c) / 10 < num && c >= 0)
		return (1);
	if (c <= 0 && num < (LONG_MIN - c) / 10)
		return (1);
	return (0);
}

long	ft_atol(const char *nptr)
{
	long	num;
	long	s;

	num = 0;
	s = 1;
	while (*nptr == ' ' || (*nptr <= 13 && *nptr >= 9))
		nptr ++;
	if (*nptr == '+')
		nptr ++;
	else if (*nptr == '-')
	{
		s = -s;
		nptr ++;
	}
	while (ft_isdigit(*nptr))
	{
		if (ft_long(num, ((*nptr - '0')) * s))
			return (ft_max(s));
		num = num * 10 + s * (*nptr - '0');
		nptr ++;
	}
	return (num);
}

int	is_overflow(const char *nptr)
{
	long	num;
	int		s;

	num = 0;
	s = 1;
	while (*nptr == ' ' || (*nptr <= 13 && *nptr >= 9))
		nptr ++;
	if (*nptr == '+')
		nptr ++;
	else if (*nptr == '-')
	{
		s = -s;
		nptr ++;
	}
	while (ft_isdigit(*nptr))
	{
		if (ft_long(num, ((*nptr - '0')) * s))
			return (1);
		num = num * 10 + s * (*nptr - '0');
		nptr ++;
	}
	return (0);
}
