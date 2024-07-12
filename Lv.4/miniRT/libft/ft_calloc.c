/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:07:09 by dtakamat          #+#    #+#             */
/*   Updated: 2024/04/19 14:09:21 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_max(size_t a, size_t b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;

	if (nmemb != 0 && (SIZE_MAX / nmemb) <= size)
		return (NULL);
	result = (void *)malloc(nmemb * size);
	if (result == NULL)
	{
		free(result);
		return (NULL);
	}
	ft_memset(result, 0, ft_max(1, nmemb * size));
	return (result);
}
