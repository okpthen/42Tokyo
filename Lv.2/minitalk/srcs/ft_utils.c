/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 07:07:10 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/05/03 17:59:43 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

size_t	ft_strlen1(char *str)
{
	size_t	c;

	c = 0;
	while (*str)
	{
		str++;
		c ++;
	}
	return (c);
}

int	is_digit(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int	is_pid(int i)
{
	if (1 <= i)
		return (1);
	return (0);
}

void	putstr_error(char *str)
{
	while (*str)
	{
		write(2, str, 1);
		str ++;
	}
	exit (1);
}
