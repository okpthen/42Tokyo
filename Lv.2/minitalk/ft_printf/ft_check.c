/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 19:22:17 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/04/19 14:44:18 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_variable(char c)
{
	if (c == ' ' || c == '+' || c == '#')
		return (1);
	else if (c == 'd' || c == 'i' || c == 'p' || c == 'X' || c == 'x')
		return (2);
	else if (c == 'c' || c == 's' || c == 'u' || c == '%')
		return (2);
	else
		return (0);
}

int	ft_check(char *str)
{
	int		i;
	t_flag	flag;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i ++;
			while (ft_is_variable(str[i]) == 1)
			{
				flag = ft_flag(str, i, flag);
				i += flag.c;
			}
			if (!ft_is_variable(str[i]))
			{
				ft_putstr_fd("ft_printf ie errored\n", 2);
				return (0);
			}
		}
		i ++;
	}
	return (1);
}
