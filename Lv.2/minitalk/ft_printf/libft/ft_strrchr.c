/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:09:53 by kazokada          #+#    #+#             */
/*   Updated: 2024/04/16 18:46:43 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	c = (char)c;
	last = NULL;
	while (*s)
	{
		if (*s == c)
			last = (char *)s;
		s ++;
	}
	if (*s == c)
		last = (char *)s;
	return (last);
}
