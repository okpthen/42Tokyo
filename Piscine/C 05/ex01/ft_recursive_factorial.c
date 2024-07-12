/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:55:39 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/11 16:15:17 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (0 > nb)
		return (0);
	if (nb == 0)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
}

// #include<stdio.h>
// int main (void)
// {
// 	printf("%d\n",ft_recursive_factorial(5));
// 	printf("%d\n",ft_recursive_factorial(0));
// 	printf("%d\n",ft_recursive_factorial(-1));
// 	return (0);
// }