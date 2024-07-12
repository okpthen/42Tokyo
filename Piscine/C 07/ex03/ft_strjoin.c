/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:19:31 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/13 12:52:35 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

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

char	*ft_strcat(char *dest, char *src)
{
	char	*c;

	c = dest;
	while (*dest != '\0')
		dest++;
	while (*src != '\0')
	{
		*dest = *src;
		dest ++;
		src ++;
	}
	*dest = '\0';
	return (c);
}

int	ft_total(int size, char **strs, char *sep)
{
	int	sum;
	int	i;

	sum = 0;
	i = 0;
	sum = (size - 1) * ft_strlen(sep);
	while (i < size)
	{
		sum = sum + ft_strlen(strs[i]);
		i ++;
	}
	return (sum);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		total;
	int		i;

	i = 0;
	if (size == 0)
	{
		result = malloc(1);
		*result = '\0';
		return (result);
	}
	total = ft_total(size, strs, sep);
	result = malloc(total + 1);
	if (result == NULL)
		return (NULL);
	*result = '\0';
	while (i < size)
	{
		ft_strcat(result, strs[i]);
		if (i < size -1)
			ft_strcat(result, sep);
		i ++;
	}
	return (result);
}

// #include<stdio.h>
// int main()
// {
//     char	*strs[] = {"Hello", "world", "this", "is","a","test","doraemon"};
//     char	sep[] = "?";
//     int		size = 7;

//     char	*result = ft_strjoin(size, strs, sep);
//     if (result != NULL)
//     {
//         printf("Result:%s\n", result);
//         free(result);
//     }

//     return 0;
// }