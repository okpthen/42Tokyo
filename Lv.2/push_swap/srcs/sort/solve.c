/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 04:55:31 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/05/02 15:59:48 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_inf	new_inf(t_inf inf)
{
	int	i;
	int	j;

	inf.prepivot = inf.pivot;
	inf.preleft = inf.left;
	inf.preright = inf.right;
	i = inf.left - inf.rnum;
	j = inf.right;
	inf.left = i / 2 + (i % 2);
	inf.right = i / 2;
	inf.leftpivot = inf.pivot - inf.right;
	inf.left2 = j / 2 + (j % 2);
	inf.right2 = j / 2;
	inf.rightpivot = inf.pivot + inf.left2;
	return (inf);
}

void	recursive_sort(t_num *a, t_num *b, int *arr, t_inf inf)
{
	recursive_process(a, b, arr, &inf);
	inf = new_inf(inf);
	if (inf.preleft > 3)
	{
		inf.pivot = inf.leftpivot;
		recursive_sort(a, b, arr, inf);
		inf.sorted = inf.prepivot;
		inf.left = inf.left2;
		inf.right = inf.right2;
		inf.pivot = inf.rightpivot;
		recursive_sort(a, b, arr, inf);
	}
}

void	quick_sort(t_num *a, t_num *b, int *arr, t_inf inf)
{
	inf.right = inf.num / 2;
	inf.left = inf.num / 2 + (inf.num % 2);
	inf.pivot = inf.num / 2 + (inf.num % 2);
	inf.sorted = 0;
	recursive_sort(a, b, arr, inf);
}

void	solve(t_num *a, t_num *b, int *arr, t_inf inf)
{
	if (inf.num > 5)
		quick_sort(a, b, arr, inf);
	else
		sort_dfs(a, b);
}
