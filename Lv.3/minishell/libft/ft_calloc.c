/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuhiro <kazuhiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:05:12 by kazokada          #+#    #+#             */
/*   Updated: 2024/05/21 00:43:53 by kazuhiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <limits.h>
#include <stdint.h>

void	*ft_calloc(size_t num, size_t size)
{
	void	*i;

	if (num != 0 && size != 0 && (SIZE_MAX / num) < size)
		return (NULL);
	if (num == 0 || size == 0)
	{
		num = 1;
		size = 1;
	}
	i = (void *)malloc(num * size);
	if (i == NULL)
		return (NULL);
	ft_memset(i, '\0', (num * size));
	return (i);
}
