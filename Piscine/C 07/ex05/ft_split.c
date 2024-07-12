/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:20:10 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/13 12:37:16 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_checkstr(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset ++;
	}
	return (0);
}

void	ft_insert(char *arr, char *src, char *charset)
{
	int	i;

	i = 0;
	while (!ft_checkstr(src[i], charset) && src[i])
	{
		arr[i] = src[i];
		i ++;
	}
	arr[i] = '\0';
}

void	ft_splitarr(char **arr, char *src, char *charset)
{
	int	i;
	int	c;
	int	index;

	i = 0;
	index = 0;
	while (src[i])
	{
		if (ft_checkstr(src[i], charset))
			i ++;
		else
		{
			c = 0;
			while (!ft_checkstr(src[i + c], charset) && src[i + c])
				c ++;
			arr[index] = (char *)malloc(sizeof(char) * (c + 1));
			ft_insert(arr[index], src + i, charset);
			index ++;
			i = i + c;
		}
	}
}

int	ft_size(char *str, char *charset)
{
	int	count;
	int	flag;

	flag = 0;
	count = 0;
	while (*str)
	{
		if (flag && ft_checkstr(*str, charset))
		{
			flag = 0;
		}
		if (!ft_checkstr(*str, charset) && !flag)
		{
			flag = 1;
			count ++;
		}
		str ++;
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		size;

	size = ft_size(str, charset);
	arr = (char **)malloc(sizeof(char *) * (size +1));
	arr[size] = 0;
	ft_splitarr(arr, str, charset);
	return (arr);
}

// #include<stdio.h>
// int main() {
//     char *str = "Hello,World!This,is,a,test";
//     char *charset = ",! o";
//     char **result = ft_split(str, charset);

//     int i = 0;
//     while (result[i] != NULL) {
//         printf("%s\n", result[i]);
//         free(result[i]);
//         i++;
//     }
//     free(result);

//     return 0;
// }