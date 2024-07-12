/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 07:06:02 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/05/02 16:20:04 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_inf	get_inf(t_num *a, int *arr)
{
	t_num	*index;
	int		i;
	t_inf	inf;

	i = 0;
	index = a->next;
	while (index != a)
	{
		index = index->next;
		i ++;
	}
	inf.mid = arr[i / 2];
	inf.num = i;
	inf.half = i / 2;
	inf.max = arr[i - 1];
	inf.min = arr[0];
	return (inf);
}

int	is_sorted_a(t_num *a)
{
	t_num	*list;

	list = a->next;
	while (list->next != a)
	{
		if (list->num > list->next->num)
			return (0);
		list = list->next;
	}
	return (1);
}

void	print_cmd_sub(int i)
{
	if (i == PA)
		ft_putstr("pa");
	else if (i == PB)
		ft_putstr("pb");
	else if (i == SA)
		ft_putstr("sa");
	else if (i == SB)
		ft_putstr("sb");
	else if (i == SS)
		ft_putstr("ss");
	else if (i == RA)
		ft_putstr("ra");
	else if (i == RB)
		ft_putstr("rb");
	else if (i == RR)
		ft_putstr("rr");
	else if (i == RRA)
		ft_putstr("rra");
	else if (i == RRB)
		ft_putstr("rrb");
	else if (i == RRR)
		ft_putstr("rrr");
}

void	print_cmd(t_res *res)
{
	int	i;

	i = 0;
	while (i < res->res[19])
	{
		print_cmd_sub(res->res[i]);
		i ++;
	}
}
