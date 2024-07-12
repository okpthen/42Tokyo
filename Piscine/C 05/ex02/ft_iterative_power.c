/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 16:15:22 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/11 20:46:56 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	result;

	result = 1;
	if (0 > power)
		return (0);
	if (power == 0)
		return (1);
	while (power > 0)
	{
		result = result * nb;
		power --;
	}
	return (result);
}

// #include<stdio.h>
// int main (void)
// {
// 	printf("%d\n",ft_iterative_power(2,-1));
// 	printf("%d\n",ft_iterative_power(2,0));
// 	printf("%d\n",ft_iterative_power(2,1));
// 	printf("%d\n",ft_iterative_power(2,3));
// 	return (0);
// }