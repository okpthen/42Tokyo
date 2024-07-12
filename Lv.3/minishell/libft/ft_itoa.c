/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:06:10 by kazokada          #+#    #+#             */
/*   Updated: 2024/04/16 19:18:38 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_size(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		count ++;
	}
	while (n != 0)
	{
		n /= 10;
		count ++;
	}
	return (count);
}

void	ft_number(char *number, int n, int a)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (n == -2147483648)
	{
		number[0] = '-';
		number[1] = '2';
		n = 147483648;
		i = 2;
	}
	if (n < 0)
	{
		n = -n;
		number[0] = '-';
		i ++;
	}
	while (i < a)
	{
		number[a - 1 - j] = n % 10 + '0';
		j ++;
		i ++;
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*number;
	int		a;

	a = ft_size(n);
	number = (char *)malloc(sizeof(char) * a + 1);
	if (number == NULL)
		return (NULL);
	number[a] = '\0';
	ft_number(number, n, a);
	return (number);
}
