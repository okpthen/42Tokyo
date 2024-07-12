/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:07:16 by kazokada          #+#    #+#             */
/*   Updated: 2024/04/16 18:47:42 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*src;

	c = (char)c;
	src = (const char *) s;
	while (0 < n)
	{
		if (*src == c)
			return ((void *)src);
		src ++;
		n --;
	}
	return (NULL);
}
