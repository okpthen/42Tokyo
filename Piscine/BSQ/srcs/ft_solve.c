/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:39:21 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/27 13:14:16 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	**ft_board(int **board, char *str, struct s_map map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*str)
	{
		if (*str == map.empty)
		{
			board[j][i] = 1;
			i ++;
		}
		if (*str == map.obstacle)
		{
			board[j][i] = 0;
			i ++;
		}
		if (*str == '\n')
		{
			i = 0;
			j ++;
		}
		str ++;
	}
	return (board);
}

int	**ft_skipboard(int **board, char *str, struct s_map map)
{
	int	**arr;

	while (*str != '\n')
		str ++;
	str ++;
	arr = ft_board(board, str, map);
	return (arr);
}

void	ft_solve(struct s_map map, char *str)
{
	int	**board;
	int	i;

	i = 0;
	board = malloc(sizeof(int *) * map.y);
	while (i < map.y)
	{
		board[i] = malloc(sizeof(int) * map.x);
		i ++;
	}
	board = ft_skipboard(board, str, map);
	board = answer_board(board, map);
	ft_print(board, map);
	ft_freeall(board, map);
}
