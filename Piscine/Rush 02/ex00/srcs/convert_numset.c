/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoishi <yoishi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:45:37 by yoishi            #+#    #+#             */
/*   Updated: 2024/02/25 23:05:55 by yoishi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush2.h"

int			count_len(char *nbr);
int			ft_strlen(char *str);
int			check_nbr(char *nbr);
int			ft_atoi(char *str, int rest, int start);

t_numset	*convert_numset(char *nbr)
{
	t_numset	*numset;
	int			size;
	int			i;

	size = count_len(nbr);
	if (size < 0)
		return (NULL);
	numset = (t_numset *)malloc(sizeof(t_numset) * size);
	if (numset == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (*nbr == '+')
			nbr++;
		numset[i].power = i;
		numset[i].num = ft_atoi(nbr, ft_strlen(nbr) - (3 * i), (i + 1) * 3);
		i++;
	}
	return (numset);
}

int	ft_atoi(char *str, int rest, int start)
{
	int	i;
	int	ans;
	int	len;

	ans = 0;
	i = 0;
	len = ft_strlen(str);
	if (rest < 3)
		start -= 3 - rest;
	while (i < 3 && i < rest)
	{
		if (str[len - start + i])
			ans = ans * 10 + (str[len - start + i] - 48);
		i++;
	}
	return (ans);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

int	count_len(char *nbr)
{
	int	ans;

	if (!check_nbr(nbr))
		return (-1);
	if (*nbr == '+')
		nbr++;
	while (*nbr == '0')
		nbr++;
	if (*nbr == '\0')
		return (1);
	ans = ft_strlen(nbr) / 3;
	if (ft_strlen(nbr) % 3)
		ans++;
	return (ans);
}

int	check_nbr(char *nbr)
{
	if (*nbr == '+')
		nbr++;
	if (*nbr == '\0')
		return (0);
	while (*nbr)
	{
		if (!('0' <= *nbr && *nbr <= '9'))
			return (0);
		nbr++;
	}
	return (1);
}
