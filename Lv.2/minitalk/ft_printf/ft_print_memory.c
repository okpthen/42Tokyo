/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:22:06 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/04/19 13:13:30 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_memory(unsigned long int addr, int i)
{
	int				count;
	unsigned int	k;

	count = 0;
	if (i == 1)
	{
		count += ft_putstr_count("0x");
		i = 0;
	}
	k = addr % 16;
	if (addr >= 16)
		count += ft_print_memory(addr / 16, i);
	if (k <= 9)
		count += ft_putchar_count(k + '0');
	else
		count += ft_putchar_count(k - 10 + 'a');
	return (count);
}
