/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedict.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 10:20:42 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/25 23:06:40 by yoishi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush2.h"

void	ft_freedict(struct s_dict *dict)
{
	int	i;

	i = 0;
	if (dict != NULL)
	{
		while (dict[i].word)
		{
			free(dict[i].word);
			i++;
		}
	}
	free(dict);
}

struct s_dict	*free_arr(char **arr, struct s_dict *dict)
{
	char	**start;

	if (arr == NULL)
		return (NULL);
	start = arr;
	while (*arr)
	{
		free(*arr);
		arr++;
	}
	free(start);
	ft_freedict(dict);
	return (NULL);
}

int	ft_returnpower(int count, int s)
{
	if (count < 4)
		return (0);
	count = count - 1;
	if (count % 3 != 0)
		return (-1);
	if (s < 0)
		return (s);
	return (count / 3);
}

int	count_words(char *str)
{
	int	i;

	i = 0;
	while (32 <= str[i] && str[i] <= 126)
		i++;
	while (i != 0 && str[i - 1] == ' ')
		i--;
	return (i);
}
