/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuhiro <kazuhiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 06:24:56 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/05/01 20:02:47 by kazuhiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	*make_arr(t_num *a, int size)
{
	int		*arr;
	t_num	*list;
	int		i;

	i = 0;
	arr = malloc(4 * size);
	if (arr == NULL)
		return (NULL);
	list = a->next;
	while (i < size)
	{
		arr[i] = list->num;
		i ++;
		list = list->next;
	}
	return (arr);
}

void	sort_arr(int *arr, int size)
{
	int	i;
	int	j;
	int	swap;

	i = 0;
	while (i < size -1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				swap = arr[i];
				arr[i] = arr[j];
				arr[j] = swap;
			}
			j ++;
		}
		i ++;
	}
}

int	a_size(t_num *a)
{
	int		size;
	t_num	*list;

	list = a->next;
	size = 0;
	while (list != a)
	{
		size ++;
		list = list->next;
	}
	return (size);
}

int	check_duplicates(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size -1)
	{
		if (arr[i] == arr[i + 1])
			return (1);
		i ++;
	}
	return (0);
}

int	*sorted_arr(t_num *a)
{
	int		*arr;
	int		size;

	size = a_size(a);
	arr = make_arr(a, size);
	if (arr == NULL)
		return (NULL);
	sort_arr(arr, size);
	if (check_duplicates(arr, size))
	{
		free(arr);
		return (NULL);
	}
	return (arr);
}
