/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 03:49:15 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/04/19 13:10:43 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <stdio.h>

typedef struct s_flag
{
	int	sharp;
	int	plus;
	int	space;
	int	c;
}		t_flag;

int		ft_putchar_count(char c);
int		ft_putstr_count(const char *str);
int		ft_putnbr_count(int nb, int count, t_flag flag);
int		ft_putnbr_base_count(unsigned int num, int i, int count, t_flag flag);
int		ft_putunsinednbr_count(unsigned int nb, int count);
int		ft_print_memory(unsigned long int addr, int i);
int		ft_check(char *str);
t_flag	ft_flag(char *str, int i, t_flag flag);
int		ft_printf(const char *format, ...);

#endif