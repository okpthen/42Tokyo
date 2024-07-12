/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:19:01 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/13 13:12:26 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	size;
	int	i;

	i = 0;
	if (min >= max)
		return (NULL);
	size = max - min;
	arr = malloc(size * 4);
	if (arr == NULL)
		return (NULL);
	while (min < max)
	{
		arr[i] = min;
		i ++;
		min ++;
	}
	return (arr);
}

// #include <stdio.h>
// int main()
// {
//     int min = 1;
//     int max = 10;

//     int *range = ft_range(min, max);

//     if (range != NULL) 
// 	{
//         for (int i = 0; i < max - min; i++)
// 		{
//             printf("%d ", range[i]);
//         }
//         printf("\n");
//         free(range);
//     }
// 	else
// 	{
//         printf("failed\n");
//     }

//     return 0;
// }