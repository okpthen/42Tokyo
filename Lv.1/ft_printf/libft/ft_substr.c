/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:10:08 by kazokada          #+#    #+#             */
/*   Updated: 2024/04/17 18:15:33 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*src;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (start > size)
		return (ft_strdup(""));
	if (size - start < len)
		len = size - start;
	src = malloc(sizeof(char) * len + 1);
	if (src == NULL)
		return (NULL);
	size = 0;
	while (size < len && s[size + start])
	{
		src[size] = s[size + start];
		size ++;
	}
	src[size] = '\0';
	return (src);
}
