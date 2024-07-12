/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:09:45 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/19 18:48:05 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < length)
	{
		if (f(tab[i]))
			count ++;
		i ++;
	}
	return (count);
}

// #include<stdio.h>
// int is_longer_than_five(char *str) {
//     int count = 0;
//     while (str[count] != '\0') {
//         count++;
//     }
//     return count >= 7;
// }

// int main() {
//     char *strings[] = {"Hello", "World", "!", "C", "Programming"};
//     int count = ft_count_if(strings, 5, &is_longer_than_five);

//     printf("%d\n", count);

//     return 0;
// }