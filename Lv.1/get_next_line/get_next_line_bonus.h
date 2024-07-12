/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:52:15 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/04/22 12:44:16 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
// # include<fcntl.h>
// # include<stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# ifndef FD_SIZE
#  define FD_SIZE 10240
# endif

char	*ft_strcat(char *dest, char *src);
int		check_newline(char *str);
char	*get_next_line(int fd);
char	*free_str(char	*str);
char	*free_str2(char *str1, char *str2);

#endif