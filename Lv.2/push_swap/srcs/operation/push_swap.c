/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuhiro <kazuhiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 07:17:25 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/04/29 17:40:36 by kazuhiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	add_number(t_num *node, int num)
{
	t_num	*new;
	t_num	*list;

	list = node->next;
	new = malloc(sizeof(t_num));
	new->num = num;
	new->next = list;
	new->prev = node;
	node->next = new;
	list->prev = new;
}

void	delite_number(t_num *sub)
{
	t_num	*del;
	t_num	*head;

	del = sub->next;
	head = del->next;
	sub->next = head;
	head->prev = sub;
	free(del);
}

void	ft_push(t_num *add, t_num *sub, int i)
{
	if (sub->next == sub)
		return ;
	add_number(add, sub->next->num);
	delite_number(sub);
	if (i == 1)
		ft_putstr("pa");
	if (i == 2)
		ft_putstr("pb");
}

void	ft_swap_s(t_num *a, t_num *b, int i)
{
	ft_swap(a, 100);
	ft_swap(b, 100);
	if (i == 1)
		ft_putstr("ss");
}

void	ft_swap(t_num *node, int a)
{
	int		i;
	t_num	*d;

	if (node->next->next == node)
		return ;
	if (node->next == node)
		return ;
	d = node->next;
	i = d->num;
	d->num = d->next->num;
	d->next->num = i;
	if (a == 1)
		ft_putstr("sa");
	if (a == 2)
		ft_putstr("sb");
}
