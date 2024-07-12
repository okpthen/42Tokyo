/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 01:51:28 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/05/02 16:56:27 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	process_3sub2(t_num *a)
{
	if (a->next->num > a->next->next->num)
		ft_swap(a, 1);
	rotate(a, 1);
	if (a->next->num > a->next->next->num)
		ft_swap(a, 1);
	rotate(a, 1);
	rotate(a, 1);
}

void	process_3sub1(t_num *a, t_num *b, t_inf *inf)
{
	int	i;

	i = 0;
	ft_push(b, a, 2);
	if (a->next->num > a->next->next->num)
		ft_swap(a, 1);
	while (i < 3)
	{
		if (b->next == b)
			rotate(a, 1);
		else if (b->next->num > a->next->num && inf->min != a->next->num)
			rotate(a, 1);
		else
		{
			ft_push(a, b, 1);
			rotate(a, 1);
		}
		i ++;
	}
}

int	check_element(t_num *a)
{
	int	e1;
	int	e2;
	int	e3;

	e1 = a->next->num;
	e2 = a->next->next->num;
	e3 = a->prev->num;
	if (e1 < e2 && e1 < e3 && e2 > e3)
		return (1);
	else if (e1 > e2 && e1 < e3 && e2 < e3)
		return (2);
	else if (e1 < e2 && e1 > e3 && e2 > e3)
		return (3);
	else if (e1 > e2 && e1 > e3 && e2 > e3)
		return (4);
	else if (e1 > e2 && e1 > e3 && e2 < e3)
		return (5);
	else if (e1 < e2 && e1 < e3 && e2 < e3)
		return (6);
	return (0);
}

void	sort_element3(t_num *a, int i)
{
	int	s;

	s = check_element(a);
	if (s == 1)
	{
		reversr_rotate(a, i);
		ft_swap(a, i);
	}
	else if (s == 2)
		ft_swap(a, i);
	else if (s == 3)
		reversr_rotate(a, i);
	else if (s == 4)
	{
		rotate(a, i);
		ft_swap(a, i);
	}
	else if (s == 5)
		rotate(a, i);
}

void	process_2_sub(t_num *a, t_num *b, t_inf *inf)
{
		inf->rnum = 0;
	while (0 < inf-> k && inf->left > 3 && (0 < inf->j))
	{
		reversr_rotate_r(a, b, 1);
		inf-> k --;
		inf-> j --;
	}
	while (0 < inf-> k)
	{
		rotate(b, 2);
		inf-> k --;
	}
	while (0 < inf->j && inf->num / 2 != inf->right)
	{
		reversr_rotate(a, 1);
		inf->j --;
	}
}
