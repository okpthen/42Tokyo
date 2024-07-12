/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:08:19 by dtakamat          #+#    #+#             */
/*   Updated: 2024/04/16 17:33:55 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	result = (char *)malloc(sizeof (char) * (ft_strlen(s) + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s[i] != 0)
	{
		if (f == NULL)
			result[i] = s[i];
		else
			result[i] = f(i, s[i]);
		i++;
	}
	result[i] = 0;
	return (result);
}
