/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 03:49:53 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/07 08:03:20 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	number;

	number = *b;
	*b = *a;
	*a = number;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size -1)
	{
		j = i +1;
		while (j < size)
		{
			if (tab[i] > tab[j])
				ft_swap (&tab[i], &tab[j]);
				j++;
		}
		i++;
	}
}

// #include <stdio.h>
// int main()
// {
//     int array[] = {5, 2, 9, 1, 7, 10, -7};
//     int size = sizeof(array) / sizeof(array[0]);

//     for (int i = 0; i < size; i++)
//     {
//         printf("%d ", array[i]);
//     }
//     printf("\n");

//     ft_sort_int_tab(array, size);

//     for (int i = 0; i < size; i++)
//     {
//         printf("%d ", array[i]);
//     }
//     printf("\n");

//     return 0;
// }