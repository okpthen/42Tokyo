/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 07:41:22 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/05/02 16:18:37 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// void	swap_ab(t_num *a, t_num *b, t_inf *inf)
// {
// 	// int	ann;

// 	// ann = a->next->next->num;
// 	// if (inf->left == 3 && inf->right == 2)
// 	// {
// 	// 	if (a->next->num > a->next->next->num)
// 	// 		ft_swap(a, 1);
// 	// }
// 	// else if (inf->left == 2 && inf->right == 2)
// 	// {
// 	// 	if (b->next->num < b->next->next->num && a->next->num > ann)
// 	// 		ft_swap_s(a, b, 1);
// 	// 	else if (b->next->num < b->next->next->num)
// 	// 		ft_swap(b, 2);
// 	// 	else if (a->next->num > a->next->next->num)
// 	// 		ft_swap(a, 1);
// 	// }
// 	// else if (inf->left == 2)
// 	// {
// 	// 	if (b->next->num < b->next->next->num)
// 	// 		ft_swap(b, 2);
// 	// }
// 	// display2(a, b);
// 	if (inf->left == 3)
// 		left_3(a, b);
// 	else if (inf->left == 4)
// 		left_4(a, b);
// 	else if (inf->left == 5)
// 		left_5(a, b);
// 		// display2(a,b);
// 	if (inf->right == 3)
// 		right_3(a, b);
// 	else if (inf->right == 4)
// 		right_4(a, b);
// 	else if (inf->right == 5)
// 		right_5(a, b);
// 	else if (inf->right == 2)
// 		right_2(a, b);
// 	// display2(a, b);
// 	printf("-------------------------------------------");
// }

// void	rotate_swap(t_num *a, t_num *b, t_inf *inf)
// {
// 	while (0 < inf->j && inf->num / 2 != inf->right)
// 	{
// 		reversr_rotate(a, 1);
// 		inf->j --;
// 	}
// 	if (inf->left == 3 || inf->left == 4 || inf->left == 5)
// 		swap_ab(a, b, inf);
// 	else
// 	{
// 		while (0 < inf->i)
// 		{
// 			ft_push(a, b, 1);
// 			inf->i --;
// 		}
// 	}
// 	// if (inf->left + inf->right <= 4)
// 	// {
// 	// 	// printf("-----ここあるよ%d-----\n", inf->right + inf->left);
// 	// 	int i;
// 	// 	i = 0;
// 	// 	while (i < inf->right + inf->left)
// 	// 	{
// 	// 		rotate(a, 1);
// 	// 		i ++;
// 	// 	}
// 	// }
// }

void	process_3(t_num *a, t_num *b, t_inf *inf)
{
	int	annn;

	annn = a->next->next->next->num;
	if (inf->right == 1)
		rotate(a, 1);
	if (inf->right == 2 && (a->next->num > a->next->next->num))
		ft_swap(a, 1);
	if (inf->right == 2)
	{
		rotate(a, 1);
		rotate(a, 1);
	}
	else if (inf->right == 3)
	{
		if (annn < a->next->next->num && annn < a->next->num)
			process_3sub1(a, b, inf);
		else
			process_3sub2(a);
	}
	if (inf->right == 1 || inf->right == 2 || inf->right == 3)
	{
		inf->rnum += inf->right;
		inf->sorted += inf->right;
	}
}

void	process_2(t_num *a, t_num *b, int *c, t_inf *inf)
{
	process_2_sub(a, b, inf);
	if (inf->left == 3)
		sort_element3(b, 2);
	if (inf->left == 4)
		sort_dfs_4(b);
	if (inf->left == 2 && (b->next->num > b->next->next->num))
		ft_swap(b, 2);
	while (0 < inf->i)
	{
		ft_push(a, b, 1);
		inf->i --;
		if (a->next->num == c[inf->sorted])
		{
			rotate(a, 1);
			inf->rnum ++;
			inf->sorted ++;
		}
	}
}

void	process_1(t_num *a, t_num *b, int *c, t_inf *inf)
{
	inf->i = 0;
	inf->j = 0;
	inf->k = 0;
	while (inf->i < inf->left)
	{
		if (a->next->num < c[inf->pivot] && c[inf->sorted] <= a->next->num)
		{
			ft_push(b, a, 2);
			if (b->next->num == c[inf->k + inf->sorted])
			{
				rotate(b, 2);
				inf-> k ++;
			}
			inf->i ++;
		}
		else
		{
			rotate(a, 1);
			inf->j ++;
		}
	}
}

void	recursive_process(t_num *a, t_num *b, int *c, t_inf *inf)
{
	inf->i = 0;
	inf->j = 0;
	if (inf->left + inf->right <= 3)
	{
		inf->right = inf->left + inf->right;
		process_3(a, b, inf);
		return ;
	}
	process_1(a, b, c, inf);
	process_2(a, b, c, inf);
	if (inf->left <= 3)
		process_3(a, b, inf);
}
