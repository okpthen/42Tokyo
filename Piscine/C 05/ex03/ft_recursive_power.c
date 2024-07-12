/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 16:22:28 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/11 20:47:01 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (0 > power)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power -1));
}

// #include<stdio.h>
// int main (void)
// {
// 	printf("%d\n",ft_recursive_power(2,-8));
// 	printf("%d\n",ft_recursive_power(2,0));
// 	printf("%d\n",ft_recursive_power(2,1));
// 	printf("%d\n",ft_recursive_power(2,3));
// 	return (0);
// }