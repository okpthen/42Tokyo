/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:07:59 by dtakamat          #+#    #+#             */
/*   Updated: 2024/04/16 17:33:18 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	uint8_t			*d;
	const uint8_t	*s;
	size_t			i;

	if (dest == NULL)
		return (0);
	if (src == NULL)
		return (dest);
	d = dest;
	s = src;
	if (d < s)
	{
		i = -1;
		while (++i < n)
			d[i] = s[i];
	}
	else if (s < d)
	{
		i = n;
		while (i-- > 0)
			d[i] = s[i];
	}
	return (dest);
}
