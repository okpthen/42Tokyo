/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuhiro <kazuhiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:19:25 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/04/09 09:16:29 by kazuhiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_putchar_count(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr_count(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		i = ft_putstr_count("(null)");
	else
	{
		while (str[i])
		{
			write (1, &str[i], 1);
			i ++;
		}
	}
	return (i);
}

int	ft_putnbr_count_sub(int nb, int count)
{
	if (nb >= 10)
		count += ft_putnbr_count_sub(nb / 10, count);
	count += ft_putchar_count(nb % 10 + '0');
	return (count);
}

int	ft_putnbr_count(int nb, int count, t_flag flag)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11 + count);
	}
	if (flag.plus && nb >= 0)
		i += ft_putchar_count('+');
	else if (flag.space && nb >= 0)
		i += ft_putchar_count(' ');
	if (nb < 0)
	{
		nb = -nb;
		i += ft_putchar_count('-');
	}
	count = ft_putnbr_count_sub(nb, count);
	return (count + i);
}

int	ft_putunsinednbr_count(unsigned int nb, int count)
{
	if (nb >= 10)
		count += ft_putunsinednbr_count(nb / 10, count);
	count += ft_putchar_count(nb % 10 + '0');
	return (count);
}
