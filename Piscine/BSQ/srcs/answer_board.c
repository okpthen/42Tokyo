/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   answer_board.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:42:24 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/27 16:43:09 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	**put_number(int **bd, int x, int y)
{
	int	low;

	low = 0;
	if (bd[y][x] == 0)
		return (bd);
	if (bd[y -1][x] >= bd [y][x - 1] && bd[y -1][x - 1] >= bd[y][x - 1])
	{	
		bd[y][x] = bd[y][x - 1] + 1;
		return (bd);
	}
	if (bd[y -1][x] >= bd [y -1][x - 1] && bd[y][x - 1] >= bd[y - 1][x - 1])
	{
		bd[y][x] = bd[y - 1][x - 1] + 1;
		return (bd);
	}
	if (bd[y][x -1] >= bd [y -1][x] && bd[y -1][x - 1] >= bd[y - 1][x])
	{
		bd[y][x] = bd[y - 1][x] + 1;
		return (bd);
	}
	return (bd);
}

struct s_square	show_board(int **board, t_map map)
{
	t_square	sq;		
	int			x;
	int			y;

	sq.size = 0;
	sq.x = 0;
	sq.y = 0;
	y = 0;
	while (y < map.y)
	{
		x = 0;
		while (x < map.x)
		{
			if (board[y][x] > sq.size)
			{
				sq.x = x;
				sq.y = y;
				sq.size = board[y][x];
			}
			x ++;
		}
		y ++;
	}
	return (sq);
}

int	**set_answer(int **board, t_square s, t_map map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map.y)
	{
		x = 0;
		while (x < map.x)
		{
			if (s.x - s.size < x && x <= s.x && s.y - s.size < y && y <= s.y)
				board[y][x] = 1;
			else if (board[y][x] != 0)
				board[y][x] = 2;
			x ++;
		}
		y ++;
	}
	return (board);
}

int	**answer_board(int **board, struct s_map map)
{
	t_square	square;
	int			x;
	int			y;

	y = 1;
	while (y < map.y)
	{
		x = 1;
		while (x < map.x)
		{
			board = put_number(board, x, y);
			x ++;
		}
		y ++;
	}
	square = show_board(board, map);
	board = set_answer(board, square, map);
	return (board);
}
