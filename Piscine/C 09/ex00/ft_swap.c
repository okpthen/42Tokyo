/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 03:29:53 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/07 08:19:57 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	number;

	number = *b;
	*b = *a;
	*a = number;
}

// #include <stdio.h>
// int main()
// {
//     int x = 10;
//     int y = 20;
// 	ft_swap(&x, &y);
//     printf("x = %d, y = %d\n", x, y);
//     return 0;
// }