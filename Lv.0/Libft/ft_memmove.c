/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:07:37 by kazokada          #+#    #+#             */
/*   Updated: 2024/04/16 14:07:40 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *buf1, const void *buf2, size_t n)
{
	char		*dest;
	const char	*src;

	if (buf1 == buf2)
		return (buf1);
	dest = (char *)buf1;
	src = (const char *)buf2;
	if (dest < src)
	{
		while (n --)
			*(dest++) = *(src++);
	}
	else
	{
		while (n --)
			*(dest + n) = *(src + n);
	}
	return (buf1);
}
