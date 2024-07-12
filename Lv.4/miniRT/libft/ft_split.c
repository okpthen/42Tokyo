/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:08:06 by dtakamat          #+#    #+#             */
/*   Updated: 2024/06/12 18:02:54 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_elements(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	if (s[0] != c)
		count ++;
	while (s[i + 1] != 0)
	{
		if (s[i] == c && s[i + 1] != c)
			count ++;
		i++;
	}
	return (count);
}

static char	*ft_strndup(const char *s, size_t n)
{
	char	*result;
	size_t	i;

	result = (char *)malloc(sizeof (char) * (n + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

static char	**error_s_null(int do_free, char ***split)
{
	char	**result;
	char	**temp;

	temp = *split;
	if (do_free)
	{
		while (*temp != NULL)
		{
			free(*temp);
			temp++;
		}
		free(*split);
		return (NULL);
	}
	result = (char **)malloc(sizeof (char *) * (1));
	if (result == NULL)
		return (NULL);
	*result = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	ij[2];
	size_t	result_index;

	if (s == NULL)
		return (error_s_null(0, NULL));
	result = (char **)malloc(sizeof (char *) * (ft_count_elements(s, c) + 1));
	if (result == NULL)
		return (NULL);
	ij[0] = -1;
	result_index = 0;
	while (s[++ij[0]] != 0)
	{
		if (s[ij[0]] == c)
			continue ;
		ij[1] = 0;
		while (s[ij[0] + ij[1]] != c && s[ij[0] + ij[1]] != 0)
			ij[1]++;
		result[result_index] = ft_strndup(s + ij[0], ij[1]);
		if (result[result_index++] == NULL)
			return (error_s_null(1, &result));
		ij[0] += ij[1] - 1;
	}
	result[result_index] = NULL;
	return (result);
}
