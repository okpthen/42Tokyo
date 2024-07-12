/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:41:08 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/28 13:39:31 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>

void			ft_putstr_error(char *str);
char			*read_file(char *path);
char			*standard_input(void);
struct s_map	ft_map(char *str);
void			ft_solve(struct s_map map, char *str);
struct s_map	ft_fullobstacle(struct s_map map, char *str);
void			ft_print(int **board, struct s_map map);
void			ft_putchar(char c);
int				**answer_board(int **board, struct s_map map);
void			ft_freeall(int **board, struct s_map map);
struct s_map	ft_printable(struct s_map map, char *str);

typedef struct s_map
{
	char	empty;
	char	obstacle;
	char	full;
	int		x;
	int		y;
	int		check;
}				t_map;

typedef struct s_square
{
	int	x;
	int	y;
	int	size;
}		t_square;

#endif