/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:07:30 by kazokada          #+#    #+#             */
/*   Updated: 2024/04/16 14:07:33 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *buf1, const void *buf2, size_t n)
{
	char		*dest;
	const char	*src;
	size_t		i;

	i = 0;
	dest = (char *)buf1;
	src = (const char *)buf2;
	if ((buf1 == buf2) || n == 0)
		return (buf1);
	if (!buf1 && !buf2)
		return (0);
	while (i < n)
	{
		dest[i] = src[i];
		i ++;
	}
	return (dest);
}
