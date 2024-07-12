/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:07:40 by dtakamat          #+#    #+#             */
/*   Updated: 2024/04/15 21:08:35 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_digits(int n)
{
	if (-9 <= n && n <= 9)
		return (1);
	else
		return (ft_count_digits(n / 10) + 1);
}

static int	ft_abs1(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

char	*ft_itoa(int n)
{
	char	*result;
	size_t	i;
	size_t	n_digits;

	i = 0;
	n_digits = ft_count_digits(n);
	if (n < 0)
		i = 1;
	result = (char *)malloc(sizeof (char) * (n_digits + i + 1));
	if (result == NULL)
		return (NULL);
	if (n < 0)
		result[0] = '-';
	i += n_digits - 1;
	result[i + 1] = 0;
	if (n == 0)
		result[0] = '0';
	while (n != 0)
	{
		result[i--] = '0' + ft_abs1(n % 10);
		n /= 10;
	}
	return (result);
}
