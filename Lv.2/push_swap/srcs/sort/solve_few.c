/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_few.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuhiro <kazuhiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 09:29:22 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/05/01 21:27:57 by kazuhiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// int	check_element(t_num *a)
// {
// 	int	e1;
// 	int	e2;
// 	int	e3;

// 	e1 = a->next->num;
// 	e2 = a->next->next->num;
// 	e3 = a->prev->num;
// 	if (e1 < e2 && e1 < e3 && e2 > e3)
// 		return (1);
// 	else if (e1 > e2 && e1 < e3 && e2 < e3)
// 		return (2);
// 	else if (e1 < e2 && e1 > e3 && e2 > e3)
// 		return (3);
// 	else if (e1 > e2 && e1 > e3 && e2 > e3)
// 		return (4);
// 	else if (e1 > e2 && e1 > e3 && e2 < e3)
// 		return (5);
// 	else if (e1 < e2 && e1 < e3 && e2 < e3)
// 		return (6);
// 	return (0);
// }

// void	sort_element3_rev(t_num *b)
// {
// 	int	s;

// 	s = check_element(b);
// 	if (s == 1)
// 		rotate(b, 2);
// 	else if (s == 2)
// 		reversr_rotate(b, 2);
// 	else if (s == 3)
// 		ft_swap(b, 2);
// 	else if (s == 5)
// 	{
// 		reversr_rotate(b, 2);
// 		ft_swap(b, 2);
// 	}
// 	else if (s == 6)
// 	{
// 		ft_swap(b, 2);
// 		reversr_rotate(b, 2);
// 	}
// }

// void	sort_element3(t_num *a)
// {
// 	int	s;

// 	s = check_element(a);
// 	if (s == 1)
// 	{
// 		reversr_rotate(a, 1);
// 		ft_swap(a, 1);
// 	}
// 	else if (s == 2)
// 		ft_swap(a, 1);
// 	else if (s == 3)
// 		reversr_rotate(a, 1);
// 	else if (s == 4)
// 	{
// 		rotate(a, 1);
// 		ft_swap(a, 1);
// 	}
// 	else if (s == 5)
// 		rotate(a, 1);
// }

// void	sort_element5(t_num *a, t_num *b, t_inf inf)
// {
// 	int	i;

// 	i = 0;
// 	while (i < 2)
// 	{
// 		if (inf.mid > a->next->num)
// 		{
// 			ft_push(b, a, 2);
// 			i ++;
// 		}
// 		else
// 			rotate(a, 1);
// 	}
// 	if (b->next->num < b->next->next->num)
// 		ft_swap(b, 2);
// 	sort_element3(a);
// 	while (0 < i)
// 	{
// 		ft_push(a, b, 1);
// 		i --;
// 	}
// }

// void	sort_element6(t_num *a, t_num *b, t_inf inf)
// {
// 	int	i;

// 	i = 0;
// 	while (i < 3)
// 	{
// 		if (inf.mid > a->next->num)
// 		{
// 			ft_push(b, a, 2);
// 			i ++;
// 		}
// 		else
// 			rotate(a, 1);
// 	}
// 	sort_element3(a);
// 	sort_element3_rev(b);
// 	while (0 < i)
// 	{
// 		ft_push(a, b, 1);
// 		i --;
// 	}
// }

void	move_cmd(t_num *a, t_num *b, int cmd)
{
	if (cmd == SA)
		ft_swap(a, 0);
	else if (cmd == SB)
		ft_swap(b, 0);
	else if (cmd == SS)
		ft_swap_s(a, b, 0);
	else if (cmd == PA)
		ft_push(a, b, 0);
	else if (cmd == PB)
		ft_push(b, a, 0);
	else if (cmd == RA)
		rotate(a, 0);
	else if (cmd == RB)
		rotate(b, 0);
	else if (cmd == RR)
		rotate_r(a, b, 0);
	else if (cmd == RRA)
		reversr_rotate(a, 0);
	else if (cmd == RRB)
		reversr_rotate(b, 0);
	else if (cmd == RRR)
		reversr_rotate_r(a, b, 0);
}

void	re_move_cmd(t_num *a, t_num *b, int cmd, int flag)
{
	if (cmd == SA)
		ft_swap(a, 0);
	else if (cmd == SB)
		ft_swap(b, 0);
	else if (cmd == SS)
		ft_swap_s(a, b, 0);
	else if (cmd == PA && flag != 1)
		ft_push(b, a, 0);
	else if (cmd == PB && flag != 2)
		ft_push(a, b, 0);
	else if (cmd == RA)
		reversr_rotate(a, 0);
	else if (cmd == RB)
		reversr_rotate(b, 0);
	else if (cmd == RR)
		reversr_rotate_r(a, b, 0);
	else if (cmd == RRA)
		rotate(a, 0);
	else if (cmd == RRB)
		rotate(b, 0);
	else if (cmd == RRR)
		rotate_r(a, b, 0);
}

void	save_result(t_res *res, int ins)
{
	int	i;

	i = 0;
	while (i < ins)
	{
		res->res[i] = res->save[i];
		i ++;
	}
	res->res[19] = i;
}

void	serch_res(t_num *a, t_num *b, t_res *res, int ins)
{
	int	cmd;
	int	flag;

	cmd = 0;
	flag = 0;
	while (cmd < 11 && ins < res->res[19])
	{
		res->save[ins -1] = cmd;
		if (cmd == PA && b->next == b)
			flag = 1;
		if (cmd == PB && a->next == a)
			flag = 2;
		move_cmd(a, b, cmd);
		if (is_sorted_a(a) && b->next == b)
		{
			save_result(res, ins);
			re_move_cmd(a, b, cmd, flag);
			return ;
		}
		serch_res(a, b, res, ins + 1);
		re_move_cmd(a, b, cmd, flag);
		cmd ++;
	}
}

void	sort_dfs(t_num *a, t_num *b)
{
	t_res	*res;

	res = malloc (sizeof(t_res));
	if (!res)
	{
		ft_putstr_error("malloc error\n");
		return ;
	}
	res->res[19] = 9;
	serch_res(a, b, res, 1);
	print_cmd(res);
	free(res);
}
