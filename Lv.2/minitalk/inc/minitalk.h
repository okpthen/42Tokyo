/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 20:32:51 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/05/03 17:59:59 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <wchar.h>
# include <string.h>

int		is_pid(int i);
int		is_digit(char c);
size_t	ft_strlen1(char *str);
void	putstr_error(char *str);

#endif