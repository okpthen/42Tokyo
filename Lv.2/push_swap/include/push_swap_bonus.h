/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:28:31 by kazokada          #+#    #+#             */
/*   Updated: 2024/05/02 16:30:48 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define SA 0
# define SB 1
# define SS 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10
# define END -1
# define ERROR_NUMBER 9999999999
# define ERROR_NUMBER1 100

typedef struct s_num
{
	int				num;
	struct s_num	*next;
	struct s_num	*prev;
}		t_num;

typedef struct s_inf
{
	int	num;
	int	half;
	int	mid;
	int	right;
	int	left;
	int	size;
	int	leftpivot;
	int	rightpivot;
	int	pivot;
	int	left2;
	int	right2;
	int	max;
	int	min;
	int	i;
	int	j;
	int	k;
	int	sorted;
	int	rnum;
	int	preright;
	int	preleft;
	int	prepivot;
}	t_inf;

typedef struct s_res
{
	int	res[20];
	int	save[20];
}	t_res;

int		*sorted_arr(t_num *a);
long	ft_atol(char *str);
int		ft_putstr_error(char *str);
void	ft_putstr(char *str);
int		make_list(int argc, char **argv);
t_num	*start_node(void);
void	add_node(t_num *node, long num);
int		free_node(t_num *a, t_num *b, int *arr);
int		free_node_error(t_num *a, t_num *b);
void	ft_push(t_num *add, t_num *sub, int i);
void	ft_swap(t_num *node, int i);
void	ft_swap_s(t_num *a, t_num *b, int i);
void	rotate(t_num *node, int i);
void	rotate_r(t_num *a, t_num *b, int i);
void	reversr_rotate(t_num *node, int i);
void	reversr_rotate_r(t_num *a, t_num *b, int i);
t_inf	get_inf(t_num *a, int *c);
int		is_sorted_a(t_num *a);

void	display1(t_num *node);
void	display2(t_num *a, t_num *b);

#endif