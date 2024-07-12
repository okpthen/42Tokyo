/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 09:00:50 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/11 09:00:50 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

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

void	ft_putnbr_base(int nbr, char *base)
{
	long	l;
	int		a;

	a = 0;
	l = nbr;
	if (ft_check(base) == 0)
		return ;
	while (base[a] != '\0')
		a ++;
	if (l < 0)
	{
		l = -l;
		ft_putchar('-');
	}
	if (l >= a)
		ft_putnbr_base(l / a, base);
	ft_putchar(base[l % a]);
}

// int main ()
// {
// 	char	t1[20] = "01";
// 	char	t2[20] = "0123456789abcdef";
// 	char	t3[20] = "01234567";
// 	ft_putnbr_base(-2147483648,t1);
// 	ft_putchar('\n');
// 	ft_putnbr_base(-2147483648,t2);
// 	ft_putchar('\n');
// 	ft_putnbr_base(-2147483648,t3);
// 	return 0;
// }