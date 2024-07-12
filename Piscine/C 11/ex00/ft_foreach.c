/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:51:07 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/19 16:17:19 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i ++;
	}
}

// #include<stdio.h>
// void print_int(int num) {
//     printf("%d ", num);
// }
// int main() {
//     int array[] = {1, 2, 3, 4, 5};
//     int length = sizeof(array) / sizeof(array[0]);

//     printf("Array elements: ");
//     ft_foreach(array, length, &print_int);

//     return 0;
// }