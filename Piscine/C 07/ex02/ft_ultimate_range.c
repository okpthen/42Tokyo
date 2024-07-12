/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:19:17 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/13 19:09:04 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;
	int	*arr;

	i = 0;
	if (min >= max)
		return (0);
	size = max - min;
	arr = malloc(size * 4);
	if (arr == NULL)
		return (-1);
	while (min < max)
	{
		arr[i] = min;
		min ++;
		i ++;
	}
	*range = arr;
	return (size);
}

// #include <stdio.h>
// int main()
// {
//     int *range = NULL;
//     int min = 5;
//     int max = 10;

//     int size = ft_ultimate_range(&range, min, max);

//     if (size >= 0)
// 	{
//         for (int i = 0; i < size; i++)
// 		{
//             printf("%d ", range[i]);
//         }
//         printf(";%d\n", size);
//         free(range);
//     }
// 	else
// 	{
//         printf("failed.\n");
//     }

//     return 0;
// }