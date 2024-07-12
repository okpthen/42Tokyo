/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:05:33 by dtakamat          #+#    #+#             */
/*   Updated: 2024/04/15 21:05:39 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_space(char c)
{
	if (9 <= c && c <= 13)
		return (1);
	else if (c == ' ')
		return (1);
	else
		return (0);
}

static int	ft_is_overflow(long num, char c, int sign)
{
	if (sign == 1)
	{
		if (((LONG_MAX - (c - '0')) / 10) < num)
			return (1);
		else
			return (0);
	}
	else
	{
		if (((LONG_MIN + (c - '0')) / 10 > num))
			return (-1);
		else
			return (0);
	}
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		sign;
	long	num;

	if (nptr == NULL)
		return (0);
	i = 0;
	sign = 1;
	while (ft_is_space(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			sign = -1;
	num = 0;
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		if (ft_is_overflow(num, nptr[i], sign) == 1)
			return ((int)LONG_MAX);
		else if (ft_is_overflow(num, nptr[i], sign) == -1)
			return ((int)LONG_MIN);
		num = num * 10 + (nptr[i++] - '0') * sign;
	}
	return (num);
}
