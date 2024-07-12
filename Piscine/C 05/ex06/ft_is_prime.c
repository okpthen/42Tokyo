/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:57:15 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/11 20:46:03 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb < 2)
		return (0);
	while (i <= (nb / 2))
	{
		if (nb % i == 0)
			return (0);
		i ++;
	}
	return (1);
}

// #include<stdio.h>
// int main ()
// {
// 	printf("%d\n",ft_is_prime(0));
// 	printf("%d\n",ft_is_prime(1));
// 	printf("%d\n",ft_is_prime(2));
// 	printf("%d\n",ft_is_prime(3));
// 	printf("%d\n",ft_is_prime(4));
// 	printf("%d\n",ft_is_prime(5));
// 	printf("%d\n",ft_is_prime(2147483647));
// 	return 0;
// }