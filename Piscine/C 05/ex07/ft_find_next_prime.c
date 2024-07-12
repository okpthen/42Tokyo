/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:57:30 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/11 18:07:57 by kazokada         ###   ########.fr       */
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

int	ft_find_next_prime(int nb)
{
	while (nb < 2147483647 && ft_is_prime(nb) != 1)
		nb ++;
	return (nb);
}

// #include<stdio.h>
// int main ()
// {
// 	printf("%d\n",ft_find_next_prime(3));
// 	printf("%d\n",ft_find_next_prime(22));
// 	printf("%d\n",ft_find_next_prime(5));
// 	return 0;
// }