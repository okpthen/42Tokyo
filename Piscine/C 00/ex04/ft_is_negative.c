/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 00:36:33 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/08 15:22:36 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	if (n >= 0)
		write(1, "P", 1);
	if (n < 0)
		write(1, "N", 1);
}

// int main(void)
// {
// 	ft_is_negative(69);
// 	ft_is_negative(0);
// 	ft_is_negative(-6);
// 	return 0;
// }