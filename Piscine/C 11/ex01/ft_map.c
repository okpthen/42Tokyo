/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:57:27 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/19 16:24:06 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*result;
	int	i;

	result = malloc (4 * length);
	if (result == NULL)
		return (0);
	i = 0;
	while (i < length)
	{
		result[i] = f(tab[i]);
		i ++;
	}
	return (result);
}

// int double_value(int value)
// {
//     return value * 2;
// }

// int main()
// {
//     int array[] = {1, 2, 3, 4, 5};
//     int length = sizeof(array) / sizeof(array[0]);
//     int *doubled_array = ft_map(array, length, &double_value);
//     for (int i = 0; i < length; i++) {
//         printf("%d ", doubled_array[i]);
//     }
//     printf("\n");

//     free(doubled_array);

//     return 0;
// }