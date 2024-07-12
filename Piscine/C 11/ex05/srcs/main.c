/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 20:34:47 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/19 14:04:58 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doop.h"

int	check_op(char c)
{
	if (c == '+' || c == '-' || c == '/' || c == '*' || c == '%')
		return (1);
	return (0);
}

int	ft_operater(int i, char *c, int j)
{
	int	(*op[5])(int, int);
	int	r;

	op[0] = &ft_add;
	op[1] = &ft_sub;
	op[2] = &ft_mul;
	op[3] = &ft_div;
	op[4] = &ft_mod;
	if (*c == '+')
		r = op[0](i, j);
	if (*c == '-')
		r = op[1](i, j);
	if (*c == '*')
		r = op[2](i, j);
	if (*c == '/')
		r = op[3](i, j);
	if (*c == '%')
		r = op[4](i, j);
	return (r);
}

void	ft_doop(char **argv)
{
	int	i;
	int	j;
	int	r;

	i = ft_atoi(argv[1]);
	j = ft_atoi(argv[3]);
	if (check_op(argv[2][0]) == 0)
		ft_putchar('0');
	else if (argv[2][0] == '/' && j == 0)
		ft_putstr("Stop : division by zero");
	else if (argv[2][0] == '%' && j == 0)
		ft_putstr("Stop : modulo by zero");
	else
	{
		r = ft_operater(i, argv[2], j);
		ft_putnbr(r);
	}
	ft_putchar('\n');
}

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		ft_doop(argv);
		return (0);
	}
	else
		return (0);
}
