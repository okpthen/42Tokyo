/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:50:50 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/06/14 12:35:49 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_newline(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str ++;
	}
	return (0);
}

char	*free_str(char	*str)
{
	free(str);
	return (NULL);
}

char	*free_str2(char *str1, char *str2)
{
	free(str1);
	free(str2);
	return (NULL);
}

char	*gnl_strjoin(char *result, char *dest, char *src)
{
	char	*copy;

	copy = result;
	while (*dest)
	{
		*result = *dest;
		result ++;
		dest ++;
	}
	while (*src)
	{
		*result = *src;
		result ++;
		src ++;
	}
	*result = '\0';
	return (copy);
}

char	*gnl_strcat(char *dest, char *src)
{
	char	*result;
	int		s;
	int		d;

	s = 0;
	d = 0;
	while (dest[d])
		d ++;
	while (src[s])
		s ++;
	result = malloc(d + s + 1);
	if (result == NULL)
		return (NULL);
	result = gnl_strjoin(result, dest, src);
	free(dest);
	return (result);
}
