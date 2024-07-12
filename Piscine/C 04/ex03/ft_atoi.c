/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 09:00:41 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/11 09:00:41 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	c;
	int	number;

	c = 1;
	number = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str ++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			c = -c;
		str ++;
	}
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + (*str - '0');
		str ++;
	}
	return (number * c);
}

// #include <stdio.h>
// int main (void)
// {
// 	printf("%d\n",ft_atoi("    ---234 4a"));
// 	return (0);
// }