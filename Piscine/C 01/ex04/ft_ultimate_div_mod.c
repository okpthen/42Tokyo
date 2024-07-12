/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 03:35:47 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/07 08:16:13 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}

// #include <stdio.h>

// int main()
// {
//     int dividend = 10;
//     int divisor = 3;

//     printf("Before: b = %d,a = %d\n", dividend, divisor);
//     ft_ultimate_div_mod(&dividend, &divisor);
//     printf("After: a = %d, b = %d\n", dividend, divisor);

//     return 0;
// }