/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:52:09 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/04/22 13:41:35 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_strjoin(char *result, char *dest, char *src)
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

char	*ft_strcat(char *dest, char *src)
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
		return (free_str(dest));
	result = ft_strjoin(result, dest, src);
	free(dest);
	return (result);
}
