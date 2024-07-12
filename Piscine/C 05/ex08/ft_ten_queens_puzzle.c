/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 10:57:47 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/11 20:45:41 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_put_queen(int *arr)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = arr[i] + '0';
		write(1, &c, 1);
		i ++;
	}
	write(1, "\n", 1);
}

int	ft_check(int *queen, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (queen [i] == queen [n])
			return (0);
		if (queen [i] - queen [n] == n - i || queen [i] - queen [n] == i - n)
			return (0);
		i ++;
	}
	return (1);
}

void	ft_reursive_queen(int *queen, int *sum, int n)
{
	int		i;

	i = 0;
	while (10 > i)
	{
		queen[n] = i;
		if (ft_check(queen, n) == 1)
		{
			if (n == 9)
			{	
				ft_put_queen(queen);
				*sum = *sum + 1;
			}
			else
				ft_reursive_queen(queen, sum, n + 1);
		}
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	queen[10];
	int	sum;

	sum = 0;
	ft_reursive_queen(queen, &sum, 0);
	return (sum);
}

// #include<stdio.h>
// int main ()
// {
// 	printf ("%d\n",ft_ten_queens_puzzle());
// 	return 0;
// }