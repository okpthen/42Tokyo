/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:08:21 by kazokada          #+#    #+#             */
/*   Updated: 2024/05/09 12:23:14 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**arr_free(char **arr, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(arr[i]);
		i ++;
	}
	free(arr);
	return (NULL);
}

static size_t	ft_size(char const *s, char c)
{
	size_t	count;
	int		flag;

	flag = 0;
	count = 0;
	while (*s)
	{
		if (flag && *s == c)
			flag = 0;
		if (!flag && *s != c)
		{
			count ++;
			flag = 1;
		}
		s ++;
	}
	return (count);
}

void	ft_insert(char *arr, char const *src, char c)
{
	int	i;

	i = 0;
	while (src[i] != c && src[i])
	{
		arr[i] = src[i];
		i ++;
	}
	arr[i] = '\0';
}

char	**ft_arrsplit(char **arr, char const *s, char c)
{
	int	i;
	int	a;
	int	index;

	i = 0;
	index = 0;
	while (s[i])
	{
		if (s[i] == c)
			i ++;
		else
		{
			a = 0;
			while (s[i + a] != c && s[i + a])
				a ++;
			arr[index] = malloc(a + 1);
			if (!arr[index])
				return (arr_free (arr, index));
			ft_insert(arr[index], s + i, c);
			index ++;
			i = i + a;
		}
	}
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_size(s, c);
	arr = (char **)malloc(sizeof(char *) * (size + 1));
	if (!arr)
		return (NULL);
	arr[size] = 0;
	arr = ft_arrsplit(arr, s, c);
	return (arr);
}
