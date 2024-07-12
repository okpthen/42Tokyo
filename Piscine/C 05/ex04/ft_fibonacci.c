/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:56:42 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/11 16:35:36 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

// #include<stdio.h>
// int main (void)
// {
// 	printf("%d ",ft_fibonacci(0));
// 	printf("%d ",ft_fibonacci(1));
// 	printf("%d ",ft_fibonacci(2));
// 	printf("%d ",ft_fibonacci(3));
// 	printf("%d ",ft_fibonacci(4));
// 	printf("%d ",ft_fibonacci(5));
// 	printf("%d ",ft_fibonacci(6));
// 	printf("%d ",ft_fibonacci(7));
// 	return (0);
// }