/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:57:00 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/11 16:46:40 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long	i;

	i = 1;
	while (i * i <= nb)
	{
		if (i * i == nb)
			return (i);
		i ++;
	}
	return (0);
}

// #include<stdio.h>
// int main ()
// {
// 	printf ("%d\n",ft_sqrt(1));
// 	printf ("%d\n",ft_sqrt(5));
// 	printf ("%d\n",ft_sqrt(16));
// 	printf ("%d\n",ft_sqrt(2147483647));
// 	return (0);
// }