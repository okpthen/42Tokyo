/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 22:37:05 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/18 10:45:21 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include<unistd.h>
# include<stdlib.h>

# define X (point % 4)
# define Y (point / 4)

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		input_check(char *str);
int		ft_strlen(char *str);
void	ft_gethint(int *hint, char *str);
void	ft_slove(int *hint, int *map, int point, int *flag);
int		ft_check(int *hint, int *map, int point);
void	ft_print(int *map, int flag);
int		ft_strlen(char *str);
int		right_left(int *hint, int *map, int point);
int		left_right(int *hint, int *map, int point);
int		down_up(int *hint, int *map, int point);
int		up_down(int *hint, int *map, int point);

#endif