/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 07:32:35 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/25 23:05:44 by yoishi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush2.h"
#include <stdio.h>

int	check_line(char *str)
{
	int	i;

	i = 0;
	if ((*str < '0' || '9' < *str) && *str != '-' && *str != '+')
		return (0);
	while (('0' <= *str && *str <= '9') || *str == '-' || *str == '+')
		str++;
	if (!(*str == ' ' || *str == ':'))
		return (0);
	while (*str == ' ' || *str == ':')
	{
		if (*str == ':')
			i++;
		str++;
	}
	if (i != 1)
		return (0);
	if (!(32 <= *str && *str <= 126))
		return (0);
	while (32 <= *str && *str <= 126)
		str++;
	if (*str != '\0')
		return (0);
	return (1);
}

int	check_dict(char *str)
{
	char	**arr;
	int		i;
	int		valid;

	valid = 1;
	i = 0;
	arr = ft_split(str, "\n");
	while (arr[i])
	{
		if (check_line(arr[i]) == 0)
			valid = 0;
		free(arr[i]);
		i++;
	}
	free(arr);
	return (valid);
}

int	count_size(struct s_dict *dict)
{
	int	size;

	size = 0;
	while (dict[size].word)
		size++;
	return (size);
}

int	check_same(struct s_dict *dict)
{
	int	i;
	int	j;

	i = 0;
	while (i < count_size(dict))
	{
		j = i + 1;
		while (j < count_size(dict))
		{
			if ((dict[i].key == dict[j].key)
				&& (dict[i].power == dict[j].power))
			{
				if (dict[i].power == -1 && dict[j].power == -1)
				{
					j++;
					continue ;
				}
				else
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
