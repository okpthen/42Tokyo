/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 05:33:53 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/05/02 16:01:18 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_num	*start_node(void)
{
	t_num	*new;

	new = malloc(sizeof(t_num));
	new->next = new;
	new->prev = new;
	return (new);
}

void	add_node(t_num *node, long num)
{
	t_num	*new;
	t_num	*list;

	list = node->prev;
	new = malloc(sizeof(t_num));
	new->num = num;
	new->next = node;
	node->prev = new;
	list->next = new;
	new->prev = list;
}

int	free_node(t_num *a, t_num *b, int *arr)
{
	t_num	*list;
	t_num	*del;

	list = a->next;
	while (list != a)
	{
		del = list;
		list = list->next;
		free(del);
	}
	list = b->next;
	while (list != b)
	{
		del = list;
		list = list->next;
		free(del);
	}
	free(a);
	free(b);
	free(arr);
	return (0);
}

int	free_node_error(t_num *a, t_num *b)
{
	t_num	*list;
	t_num	*del;

	list = a->next;
	while (list != a)
	{
		del = list;
		list = list->next;
		free(del);
	}
	free(a);
	free(b);
	return (1);
}
