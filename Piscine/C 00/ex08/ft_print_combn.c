/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:15:39 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/13 14:15:39 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

void	ft_putcom(int com[], int n)
{
	int	c;

	c = 0;
	while (c < n)
	{
		ft_putchar(com[c] + '0');
		c++;
	}
}

int	ft_get_index(int combn[], int n)
{
	int	c;
	int	max;

	c = 0;
	max = 10 - n;
	while (c < n)
	{
		if (combn[c] == max)
			return (c - 1);
		if (c == (n - 1))
			return (n - 1);
		c++;
		max++;
	}
	return (-1);
}

void	ft_change(int com[], int n, int index)
{
	com[index] = com[index] + 1;
	while (index <= n -1)
	{
		com[index +1] = com [index] + 1;
		index ++;
	}
}

void	ft_print_combn(int n)
{
	int	combn[9];
	int	c;
	int	index;

	if (n >= 10 || n <= 0)
		return ;
	else
	{
		c = 0;
		while (c < n)
		{
			combn[c] = c;
			c++;
		}
		while (ft_get_index(combn, n) != -1)
		{
			index = ft_get_index(combn, n);
			ft_putcom(combn, n);
			ft_change(combn, n, index);
			write(1, ", ", 2);
		}
		ft_putcom(combn, n);
	}
}

// int main()
// {
// 	ft_print_combn(9);
// 	return 0;
// }