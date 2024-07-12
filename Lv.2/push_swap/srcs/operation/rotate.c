/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuhiro <kazuhiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 04:04:32 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/04/29 17:39:04 by kazuhiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rotate(t_num *node, int i)
{
	t_num	*end;
	t_num	*top;
	t_num	*nexttop;

	if (node->next->next == node)
		return ;
	if (node->next == node)
		return ;
	end = node->prev;
	top = node->next;
	nexttop = top->next;
	node->next = nexttop;
	nexttop->prev = node;
	end->next = top;
	top->prev = end;
	top->next = node;
	node->prev = top;
	if (i == 1)
		ft_putstr("ra");
	if (i == 2)
		ft_putstr("rb");
}

void	rotate_r(t_num *a, t_num *b, int i)
{
	rotate(a, 0);
	rotate(b, 0);
	if (i == 1)
		ft_putstr("rr");
}

void	reversr_rotate(t_num *node, int i)
{
	t_num	*end;
	t_num	*top;
	t_num	*nextend;

	if (node->next->next == node)
		return ;
	if (node->next == node)
		return ;
	top = node->next;
	end = node->prev;
	nextend = end->prev;
	node->prev = nextend;
	nextend->next = node;
	top->prev = end;
	end->next = top;
	node->next = end;
	end->prev = node;
	if (i == 1)
		ft_putstr("rra");
	if (i == 2)
		ft_putstr("rrb");
}

void	reversr_rotate_r(t_num *a, t_num *b, int i)
{
	reversr_rotate(a, 0);
	reversr_rotate(b, 0);
	if (i == 1)
		ft_putstr("rrr");
}
