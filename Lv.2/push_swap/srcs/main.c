/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 23:32:14 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/05/02 16:19:13 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_swap(t_num *a, t_num *b, int *arr)
{
	t_inf	inf;

	inf = get_inf(a, arr);
	if (inf.num == 0)
	{
		ft_putstr_error("Error\n");
		return ;
	}
	if (is_sorted_a(a))
		return ;
	solve(a, b, arr, inf);
}

int	make_list(int argc, char **argv)
{
	t_num	*a;
	t_num	*b;
	int		*arr;
	int		i;
	long	num;

	a = start_node();
	b = start_node();
	i = 1;
	while (i < argc)
	{
		num = ft_atol(argv[i]);
		if (num == ERROR_NUMBER)
			return (free_node_error(a, b));
		add_node(a, num);
		i ++;
	}
	arr = sorted_arr(a);
	if (arr == NULL)
		return (free_node_error(a, b));
	push_swap(a, b, arr);
	return (free_node(a, b, arr));
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	if (make_list(argc, argv))
		return (ft_putstr_error("Error\n"));
	return (0);
}
