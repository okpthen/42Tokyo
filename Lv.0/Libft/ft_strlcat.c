/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:08:53 by kazokada          #+#    #+#             */
/*   Updated: 2024/04/16 19:03:02 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t len)
{
	char	*copy;

	copy = dst;
	while (*dst)
		dst ++;
	while (0 < len && *src)
	{
		*dst = *src;
		dst ++;
		src ++;
		len --;
	}
	*dst = '\0';
	return (copy);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	max;
	size_t	d_len;
	size_t	s_len;

	if (!dst)
		return (ft_strlen(src));
	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	if (size <= d_len)
		return (size + s_len);
	max = size - d_len - 1;
	ft_strncat(dst, src, max);
	return (s_len + d_len);
}
