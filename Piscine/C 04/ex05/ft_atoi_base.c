/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 09:01:03 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/11 09:01:03 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check(char *base)
{
	char	*c;

	c = base +1;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (*base)
	{
		if (*base == ' ' || (*base <= '\r' && *base >= '\t'))
			return (0);
		if (*base == '+' || *base == '-')
			return (0);
		while (*c)
		{
			if (*base == *c)
				return (0);
			c ++;
		}
		base ++;
		c = base + 1;
	}
	return (1);
}

int	ft_stelen(char *base)
{
	int	i;

	i = 0;
	while (*base)
	{
		i ++;
		base ++;
	}
	return (i);
}

int	ft_to_number(char str, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (str == base[i])
			return (i);
		i ++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	number;
	int	i;
	int	c;

	c = ft_stelen(base);
	if (ft_check(base) == 0)
		return (0);
	i = 1;
	number = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
	str ++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
		i = -i;
		str ++;
	}
	while (ft_to_number(*str, base) != -1)
	{
		number = number * c + ft_to_number(*str, base);
		str ++;
	}
	return (number * i);
}

// #include <stdio.h>
// int main ()
// {
// 	printf ("%d\n",ft_atoi_base("aaaa","012fa"));
// 	printf ("%d\n",ft_atoi_base("100","0123456789abcdef"));
// 	return 0;
// }