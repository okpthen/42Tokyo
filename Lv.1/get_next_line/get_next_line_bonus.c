/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:52:12 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/04/22 19:24:37 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_file(int fd, char *str)
{
	int		byte;
	char	*buf;

	byte = 1;
	buf = malloc (BUFFER_SIZE + 1);
	if (!buf)
		return (free_str(str));
	while (byte > 0)
	{
		byte = read(fd, buf, BUFFER_SIZE);
		if (byte < 0)
			return (free_str2(str, buf));
		buf[byte] = '\0';
		str = ft_strcat(str, buf);
		if (!str)
			return (free_str2(str, buf));
		if (check_newline(buf))
			break ;
	}
	free(buf);
	return (str);
}

char	*get_file(int fd, char *next)
{
	char		*result;

	result = malloc(1);
	if (!result)
		return (NULL);
	*result = '\0';
	result = ft_strcat(result, next);
	if (!result)
		return (NULL);
	if (check_newline(next))
		return (result);
	result = read_file(fd, result);
	return (result);
}

char	*get_result(char *str)
{
	int		i;
	char	*result;

	i = 0;
	if (str[i] == '\0')
		return (free_str(str));
	while (str[i] != '\n' && str[i])
		i ++;
	result = malloc (i + 2);
	if (result == NULL)
		return (free_str(str));
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		result[i] = str[i];
		i ++;
	}
	if (str[i] == '\n')
	{
		result[i] = str[i];
		i ++;
	}
	result [i] = '\0';
	return (result);
}

void	get_next(char *next, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i ++;
	if (str[i] == '\n')
		i ++;
	while (str[i])
		next[j++] = str[i++];
	next[j] = '\0';
}

char	*get_next_line(int fd)
{
	char		*result;
	char		*str;
	static char	next[FD_SIZE][BUFFER_SIZE + 1] = {};

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = get_file(fd, next[fd]);
	if (!str)
		return (NULL);
	result = get_result(str);
	if (!result)
		return (NULL);
	get_next(next[fd], str);
	free(str);
	return (result);
}
