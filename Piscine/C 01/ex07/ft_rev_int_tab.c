/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 03:44:35 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/07 08:03:11 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	number;

	number = *b;
	*b = *a;
	*a = number;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	n;

	n = 0;
	while (n < size)
	{
		ft_swap(&tab[n], &tab[size - 1]);
		n ++;
		size--;
	}
}

// #include <stdio.h>

// int main()
// {
//     int array[] = {1, 2, 9, 4, 5, 15 ,43};
//     int size = sizeof(array) / sizeof(array[0]);

//     for (int i = 0; i < size; i++)
//     {
//         printf("%d ", array[i]);
//     }
//     printf("\n");

//     ft_rev_int_tab(array, size);

//     for (int i = 0; i < size; i++)
//     {
//         printf("%d ", array[i]);
//     }
//     printf("\n");

//     return 0;
// }
