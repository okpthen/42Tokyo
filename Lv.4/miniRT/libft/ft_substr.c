/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:08:26 by dtakamat          #+#    #+#             */
/*   Updated: 2024/04/15 21:08:35 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	s_size;

	if (s == NULL)
		return (NULL);
	s_size = ft_strlen(s);
	if (s_size <= start)
	{
		result = (char *)malloc(1);
		if (result == NULL)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	result = (char *)malloc(sizeof (char) * (ft_min(len, s_size - start) + 1));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s + start, ft_min(len, s_size - start) + 1);
	return (result);
}
