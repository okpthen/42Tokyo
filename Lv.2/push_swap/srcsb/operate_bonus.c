/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 08:34:05 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/05/02 16:31:06 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	check_move_ab(t_num *a, t_num *b, int c)
{
	if (c == SA)
		ft_swap(a, 0);
	else if (c == SB)
		ft_swap(b, 0);
	else if (c == SS)
		ft_swap_s(a, b, 0);
	else if (c == PA)
		ft_push(a, b, 0);
	else if (c == PB)
		ft_push(b, a, 0);
	else if (c == RA)
		rotate(a, 0);
	else if (c == RB)
		rotate(b, 0);
	else if (c == RR)
		rotate_r(a, b, 0);
	else if (c == RRA)
		reversr_rotate(a, 0);
	else if (c == RRB)
		reversr_rotate(b, 0);
	else if (c == RRR)
		reversr_rotate_r(a, b, 0);
}

int	decide_struction_sub(char *s)
{
	if (s[0] == 'r' && s[1] == 'r' && s[2] == 'a' && s[3] == '\n')
		return (RRA);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'b' && s[3] == '\n')
		return (RRB);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'r' && s[3] == '\n')
		return (RRR);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == '\n')
		return (RR);
	else
		return (ERROR_NUMBER1);
}

int	decide_struction(char *s)
{
	if (s[1] == '\0')
		return (ERROR_NUMBER1);
	if (s[2] == '\0')
		return (ERROR_NUMBER1);
	else if (s[0] == 's' && s[1] == 'a' && s[2] == '\n')
		return (SA);
	else if (s[0] == 's' && s[1] == 'b' && s[2] == '\n')
		return (SB);
	else if (s[0] == 's' && s[1] == 's' && s[2] == '\n')
		return (SS);
	else if (s[0] == 'p' && s[1] == 'a' && s[2] == '\n')
		return (PA);
	else if (s[0] == 'p' && s[1] == 'b' && s[2] == '\n')
		return (PB);
	else if (s[0] == 'r' && s[1] == 'a' && s[2] == '\n')
		return (RA);
	else if (s[0] == 'r' && s[1] == 'b' && s[2] == '\n')
		return (RB);
	return (decide_struction_sub(s));
}

int	operate(t_num *a, t_num *b, char *structions)
{
	int	check;

	if (!*structions)
		return (ERROR_NUMBER1);
	else if (structions[0] == '\n' && structions[1] == '\0')
		return (1);
	while (*structions)
	{
		check = decide_struction(structions);
		if (check == END)
			return (0);
		if (check == ERROR_NUMBER1)
			return (ERROR_NUMBER1);
		check_move_ab(a, b, check);
		while (*structions && *structions != '\n')
			structions ++;
		if (*structions == '\n')
			structions ++;
	}
	return (1);
}
