/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 06:00:43 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/05/02 14:37:01 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "../../include/push_swap.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isint(long num)
{
	if (num <= INT_MAX && num >= INT_MIN)
		return (1);
	return (0);
}

long	ft_atol(char *str)
{
	long	num;
	int		s;

	num = 0;
	s = 1;
	if (((*str == '+' || *str == '-') && str[1] == '\0') || *str == '\0')
		return (ERROR_NUMBER);
	if (*str == '+')
		str ++;
	if (*str == '-')
	{
		s = -s;
		str ++;
	}
	while (ft_isdigit(*str))
	{
		num = num * 10 + (*str - '0');
		if (!ft_isint(num * s))
			return (ERROR_NUMBER);
		str ++;
	}
	if (*str != '\0')
		return (ERROR_NUMBER);
	return (num * s);
}
