/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:02:35 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/04/19 13:33:37 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_upper_case(char c, int i)
{
	if (i)
		c = c - 32;
	return (c);
}

int	ft_putnbr_base_count(unsigned int num, int i, int count, t_flag flag)
{
	unsigned int	k;
	int				sharp;

	sharp = 0;
	k = num % 16;
	if (flag.sharp && i && num)
		sharp += ft_putstr_count("0X");
	else if (flag.sharp && !i && num)
		sharp += ft_putstr_count("0x");
	flag.sharp = 0;
	if (num >= 16)
		count += ft_putnbr_base_count(num / 16, i, count, flag);
	if (k <= 9)
		count += ft_putchar_count(k + '0');
	else
		count += ft_putchar_count(ft_upper_case('a' - 10 + k, i));
	return (count + sharp);
}
