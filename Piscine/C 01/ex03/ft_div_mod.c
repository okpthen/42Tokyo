/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 03:32:57 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/07 08:02:40 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

// #include <stdio.h>
// int main()
// {
//     int dividend = 10;
//     int divisor = 3;
//     int quotient, remainder;

//     ft_div_mod(dividend, divisor, &quotient, &remainder);

//     printf("a=%d, b=%d\n", dividend, divisor);
//     printf("div=%d,mod=%d\n", quotient, remainder);

//     return 0;
// }
