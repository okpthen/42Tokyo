/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuhiro <kazuhiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 10:34:48 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/04/09 09:37:05 by kazuhiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_variable(char *str, int i, t_flag flag, va_list arg)
{
	if (str[i] == '%')
		return (ft_putchar_count('%'));
	else if (str[i] == 'c')
		return (ft_putchar_count(va_arg(arg, int)));
	else if (str[i] == 's')
		return (ft_putstr_count(va_arg(arg, const char *)));
	else if (str[i] == 'p')
		return (ft_print_memory(va_arg(arg, unsigned long int), 1));
	else if (str[i] == 'd' || str[i] == 'i')
		return (ft_putnbr_count(va_arg(arg, int), 0, flag));
	else if (str[i] == 'u')
		return (ft_putunsinednbr_count(va_arg(arg, unsigned int), 0));
	else if (str[i] == 'x')
		return (ft_putnbr_base_count(va_arg(arg, unsigned int), 0, 0, flag));
	else if (str[i] == 'X')
		return (ft_putnbr_base_count(va_arg(arg, unsigned int), 1, 0, flag));
	return (0);
}

t_flag	ft_flag(char *str, int i, t_flag flag)
{
	flag.plus = 0;
	flag.sharp = 0;
	flag.space = 0;
	flag.c = 0;
	while (str[i] == ' ' || str[i] == '#' || str[i] == '+')
	{
		if (str[i] == ' ')
			flag.space += 1;
		if (str[i] == '#')
			flag.sharp += 1;
		if (str[i] == '+')
			flag.plus += 1;
		i ++;
	}
	flag.c = flag.plus + flag.sharp + flag.space;
	return (flag);
}

int	ft_start_print(char *str, va_list arg)
{
	int		i;
	int		count;
	t_flag	flag;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i ++;
			flag = ft_flag(str, i, flag);
			i += flag.c;
			count += ft_variable(str, i, flag, arg);
			i ++;
		}
		else
		{
			count += ft_putchar_count(str[i]);
			i ++;
		}
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	char	*str;
	int		count;
	va_list	arg;

	str = ft_strdup(format);
	if (!format || *format == '\0')
		return (0);
	va_start(arg, format);
	count = 0;
	if (ft_check(str))
		count = ft_start_print(str, arg);
	else
		return (-1);
	va_end(arg);
	free(str);
	return (count);
}
