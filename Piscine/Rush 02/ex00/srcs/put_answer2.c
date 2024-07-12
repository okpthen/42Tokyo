/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_answer2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoishi <yoishi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:43:51 by yoishi            #+#    #+#             */
/*   Updated: 2024/02/25 23:06:34 by yoishi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush2.h"

void	search_dict_key(int n, t_dict *dict, int *flg);

void	search_hp(int hp, t_dict *dict, int *flg)
{
	if (hp == 0)
		return ;
	search_dict_key(hp / 100, dict, flg);
	search_dict_key(100, dict, flg);
}

int	search_tp(int tp, int op, t_dict *dict, int *flg)
{
	if (tp == 0)
		return (0);
	if (tp < 20)
	{
		search_dict_key(tp + op, dict, flg);
		return (1);
	}
	else
	{
		search_dict_key(tp, dict, flg);
		return (0);
	}
}

void	search_op(int op, t_dict *dict, int *flg)
{
	if (op == 0)
		return ;
	search_dict_key(op, dict, flg);
}
