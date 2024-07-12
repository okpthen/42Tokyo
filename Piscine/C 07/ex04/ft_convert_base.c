/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:20:16 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/14 10:27:51 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>

int	ft_check(char *base);
int	ft_atoi_base(char *str, char *base);
int	ft_stelen(char *base);

int	ft_size(int nbr, int i)
{
	int	count;
	int	a;

	count = 1;
	a = i;
	if (nbr < 0)
	{
		count ++;
		nbr = -nbr;
	}
	while (i <= nbr)
	{
		i = i * a;
		count++;
	}
	return (count);
}

char	*ft_putword(char *num, int i, int t, char *base)
{
	int	a;
	int	c;
	int	ab;

	c = ft_size(i, t);
	ab = c;
	a = 1;
	if (i < 0)
	{
		i = -i;
		num[0] = '-';
		ab --;
	}
	while (ab > 0)
	{
		num[c - a] = base [i % t];
		i = i / t;
		a ++;
		ab --;
	}
	return (num);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*result;
	int		num;
	int		i;
	int		size;

	if (ft_check(base_from) == 0 || ft_check(base_to) == 0)
		return (0);
	num = ft_atoi_base(nbr, base_from);
	i = ft_stelen(base_to);
	size = ft_size(num, i);
	result = malloc (size + 1);
	result[size] = '\0';
	ft_putword(result, num, i, base_to);
	return (result);
}

// int	main(void)
// {
// //	ft_convert_base("15", "012345678", "01234567");
// 	printf ("%s\n", ft_convert_base("     -255", "0123456789", "abcdefghij"));
// 	return (0);
// }
