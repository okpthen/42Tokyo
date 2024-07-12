/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_4ele.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuhiro <kazuhiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 21:19:49 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/05/01 21:51:05 by kazuhiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	move_cmd_4(t_num *b, int cmd)
{
	if (cmd == SB)
		ft_swap(b, 0);
	else if (cmd == RB)
		rotate(b, 0);
	else if (cmd == RRB)
		reversr_rotate(b, 0);
}

void	re_move_cmd_4(t_num *b, int cmd)
{
	if (cmd == SB)
		ft_swap(b, 0);
	else if (cmd == RB)
		reversr_rotate(b, 0);
	else if (cmd == RRB)
		rotate(b, 0);
}

void	serch_res_4(t_num *b, t_res *ans, int ins)
{
	int	cmd;

	cmd = 0;
	while (cmd < 11 && ins < ans->res[19])
	{
		ans->save[ins -1] = cmd;
		move_cmd_4(b, cmd);
		if (is_sorted_a(b))
		{
			save_result(ans, ins);
			re_move_cmd_4(b, cmd);
			return ;
		}
		serch_res_4(b, ans, ins + 1);
		re_move_cmd_4(b, cmd);
		cmd ++;
	}
}

void	move_res(t_res *res, t_num *b)
{
	int	i;

	i = 0;
	while (i < res->res[19])
	{
		if (res->res[i] == SB)
			ft_swap(b, 2);
		else if (res->res[i] == RB)
			rotate(b, 2);
		else if (res->res[i] == RRB)
			reversr_rotate(b, 2);
		i ++;
	}
}

void	sort_dfs_4(t_num *b)
{
	t_res	*res;

	res = malloc (sizeof(t_res));
	if (!res)
	{
		ft_putstr_error("malloc error\n");
		return ;
	}
	res->res[19] = 7;
	serch_res_4(b, res, 1);
	move_res(res, b);
	free(res);
}
