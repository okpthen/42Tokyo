/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:24:22 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/27 16:38:56 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putstr_error(char *str)
{
	while (*str)
	{
		write (1, str, 1);
		str ++;
	}
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}
