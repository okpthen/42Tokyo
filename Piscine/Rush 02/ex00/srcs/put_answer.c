/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_answer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoishi <yoishi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:18:11 by yoishi            #+#    #+#             */
/*   Updated: 2024/02/25 23:06:30 by yoishi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush2.h"

int		search_and_put(t_numset numset, t_dict *dict, int *flg);
void	search_dict_key(int n, t_dict *dict, int *flg);
void	search_dict_power(int n, t_dict *dict, int *flg);
int		exist_dict_power(int power, t_dict *dict);
void	search_hp(int hp, t_dict *dic, int *flgt);
void	search_op(int op, t_dict *dict, int *flg);
int		search_tp(int tp, int op, t_dict *dic, int *flg);

int	put_answer(t_numset *numset, t_dict *dict, int numset_len)
{
	int	is_first;

	is_first = 0;
	if (numset_len == 0 && numset[0].num == 0 && numset[0].power == 0)
		search_dict_key(numset[0].num, dict, &is_first);
	while (numset_len >= 0)
	{
		if (!(search_and_put(numset[numset_len], dict, &is_first)))
			return (0);
		numset_len--;
	}
	write(1, "\n", 1);
	return (1);
}

int	search_and_put(t_numset numset, t_dict *dict, int *is_first)
{
	int	hp;
	int	tp;
	int	op;
	int	f;

	f = 0;
	hp = numset.num / 100 * 100;
	tp = ((numset.num % 100) / 10) * 10;
	op = (numset.num % 10);
	if (!(exist_dict_power(numset.power, dict)))
		return (0);
	search_hp(hp, dict, is_first);
	f = search_tp(tp, op, dict, is_first);
	if (!f)
		search_op(op, dict, is_first);
	if (numset.num != 0)
		search_dict_power(numset.power, dict, is_first);
	return (1);
}

void	search_dict_key(int num, t_dict *dict, int *flg)
{
	while ((*dict).word)
	{
		if ((*dict).key == num)
		{
			ft_putstr_flag((*dict).word, *flg);
			*flg = 1;
			return ;
		}
		dict++;
	}
}

void	search_dict_power(int power, t_dict *dict, int *flg)
{
	if (power == 0)
		return ;
	while ((*dict).word)
	{
		if ((*dict).key == 0 && (*dict).power == power)
		{
			ft_putstr_flag((*dict).word, *flg);
			return ;
		}
		dict++;
	}
}

int	exist_dict_power(int power, t_dict *dict)
{
	if (power == 0)
		return (1);
	while ((*dict).word)
	{
		if ((*dict).key == 0 && (*dict).power == power)
			return (1);
		dict++;
	}
	return (0);
}
