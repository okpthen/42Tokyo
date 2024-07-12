/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:08:25 by dtakamat          #+#    #+#             */
/*   Updated: 2024/04/15 21:08:35 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	is_included(char c, char const *set)
{
	size_t	i;

	if (set == NULL)
		return (0);
	i = 0;
	while (set[i] != 0)
		if (set[i++] == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	count;
	size_t	i;
	char	*result;

	if (s1 == NULL)
	{
		result = (char *)malloc(1);
		if (result != NULL)
			result[0] = '\0';
		return (result);
	}
	count = 0;
	i = ft_strlen(s1) - 1;
	while (is_included(s1[i--], set) == 1)
		count++;
	if (count == ft_strlen(s1))
		count = 0;
	i = 0;
	while (is_included(s1[i++], set) == 1)
		count++;
	result = (char *)malloc(sizeof (char) * (ft_strlen(s1) - count + 1));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s1 + i - 1, ft_strlen(s1) - count + 1);
	return (result);
}
