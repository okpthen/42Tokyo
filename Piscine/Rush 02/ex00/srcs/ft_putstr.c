/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 01:06:52 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/25 23:06:04 by yoishi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

void	ft_putstr_error(char *str)
{
	while (*str)
	{
		write(2, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

void	ft_putstr_flag(char *str, int flag)
{
	if (flag)
		write(1, " ", 1);
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}
