/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:43:51 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/14 18:18:38 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include<stdlib.h>

char	*ft_strdup(char *src)
{
	char	*copy;
	char	*p;
	int		i;

	i = 0;
	while (src[i] != '\0')
		i ++;
	copy = malloc (i +1);
	if (copy == NULL)
		return (NULL);
	p = copy;
	while (*src)
	{
		*copy = *src;
		src ++;
		copy ++;
	}
	*copy = '\0';
	return (p);
}

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (*str != '\0')
	{
		str++;
		n++;
	}
	return (n);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*arr;
	int			i;

	i = 0;
	arr = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac +1));
	if (arr == NULL)
		return (NULL);
	arr[ac].str = 0;
	while (i < ac)
	{
		arr[i].str = av[i];
		arr[i].size = ft_strlen(av[i]);
		arr[i].copy = ft_strdup(av[i]);
		i ++;
	}
	return (arr);
}
