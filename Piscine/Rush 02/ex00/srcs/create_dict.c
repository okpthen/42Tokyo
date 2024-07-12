/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_dict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 02:08:08 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/25 23:06:00 by yoishi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush2.h"

int	ft_key(char *str)
{
	int	number;
	int	flag;
	int	i;

	number = 0;
	flag = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag = -1;
		i++;
	}
	while (str[i] != ':' && str[i] != ' ' && i < 5)
	{
		if (!('0' <= str[i] && '9' >= str[i]))
			return (0);
		else
			number = number * 10 + str[i] - '0';
		i++;
	}
	if (number * flag >= 1000)
		return (0);
	return (number * flag);
}

int	ft_power(char *str)
{
	int	count;
	int	s;

	s = 0;
	count = 0;
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			return (-1);
		str++;
	}
	if (*str != '1')
		s = -1;
	while ('0' <= str[count] && str[count] <= '9')
	{
		count++;
		if ('1' <= str[count] && str[count] <= '9')
			s = -1;
	}
	return (ft_returnpower(count, s));
}

char	*ft_word(char *str)
{
	int		i;
	int		j;
	char	*word;

	i = 0;
	j = 0;
	while (('0' <= *str && *str <= '9') || *str == '-' || *str == '+')
		str++;
	while (*str == ':' || *str == ' ')
		str++;
	i = count_words(str);
	word = malloc(i + 1);
	if (word == NULL)
		return (NULL);
	while (j < i)
	{
		word[j] = str[j];
		j++;
	}
	word[j] = '\0';
	return (word);
}

int	count_key(char *str)
{
	int	count;
	int	newline;

	count = 0;
	newline = 1;
	while (*str)
	{
		if (newline && (('0' <= *str && *str <= '9') || '+' == *str
				|| '-' == *str))
		{
			count++;
			newline = 0;
		}
		else if (*str == '\n')
			newline = 1;
		else
			newline = 0;
		str++;
	}
	return (count);
}

struct s_dict	*create_dict(char *str)
{
	char	**arr;
	int		size;
	t_dict	*dict;
	int		i;

	i = 0;
	size = count_key(str);
	arr = ft_split(str, "\n");
	free(str);
	dict = (t_dict *)malloc(sizeof(t_dict) * (size + 1));
	if (dict == NULL)
		return (NULL);
	while (i < size)
	{
		dict[i].key = ft_key(arr[i]);
		dict[i].word = ft_word(arr[i]);
		dict[i].power = ft_power(arr[i]);
		if (dict[i].word == NULL)
			return (free_arr(arr, dict));
		free(arr[i]);
		i++;
	}
	dict[size].word = 0;
	free(arr);
	return (dict);
}
