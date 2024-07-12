/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:20:13 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/12 13:46:39 by kazokada         ###   ########.fr       */
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
