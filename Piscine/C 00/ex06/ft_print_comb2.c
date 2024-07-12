/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 01:13:28 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/07 02:49:39 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char a, char b, char c, char d)
{
	write (1, &a, 1);
	write (1, &b, 1);
	write (1, " ", 1);
	write (1, &c, 1);
	write (1, &d, 1);
}

void	ft_exchar(int i, int k)
{
	char	a;
	char	b;
	char	c;
	char	d;

	a = i / 10 + '0';
	b = i % 10 + '0';
	c = k / 10 + '0';
	d = k % 10 + '0';
	ft_putchar (a, b, c, d);
}

void	ft_print_comb2(void)
{
	int	i;
	int	k;

	i = 0;
	while (i <= 98)
	{
		k = i +1;
		while (k <= 99)
		{	
			ft_exchar(i, k);
			if (i != 98 || k != 99)
				write (1, ", ", 2);
			k++;
		}
		i++;
	}
}

// int	main(void)
// {
// 	ft_print_comb2();
// 	return (0);
// }
